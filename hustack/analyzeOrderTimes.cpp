#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define MAX_CUS 1000

int store[89999] = {0}, prefixtimenow[90000] = {0};

typedef struct Bst {
    char cusId[11]; 
    int totalPrice;
    struct Bst *left, *right;
} BST_customId;

typedef struct BST {
    char shopId[11]; 
    int total_revenue;
    
    BST_customId *customers;
    struct BST *left, *right;
} BST;

int convert_time(char* time) {
    int hour, minute, second;
    sscanf(time, "%d:%d:%d", &hour, &minute, &second); 
    return hour * 3600 + minute * 60 + second;
}

int total = 0;

int main() {
    std::string command; char h[20]; int timenow;

    while (std::cin >> command && command != "#") {
        scanf("%s", h);
        timenow = convert_time(h);

        store[timenow] += 1;
        total += 1;
    }

    // Build prefix array
    for (int i = 1; i <= 90000; i++) {
        prefixtimenow[i] = prefixtimenow[i - 1] + store[i - 1];
    }

    // Second loop to process commands
    while (std::cin >> command && command != "###") {
        if (command == "?number_orders") {
            std::cout << total << std::endl;
        } else if (command == "?number_orders_in_period") {
            scanf("%s", h);
            int timenow1 = convert_time(h);
            scanf("%s", h);
            int timenow2 = convert_time(h); 

            std::cout << prefixtimenow[timenow2 + 1] - prefixtimenow[timenow1] << std::endl;    
        } else {
            scanf("%s", h);
            timenow = convert_time(h);
            std::cout << store[timenow] << std::endl;
        }
    }

    return 0;
}

BST_customId* makeNode_cus(char* customId, int price) {
    BST_customId* n = (BST_customId*)malloc(sizeof(BST_customId));
    n->left = NULL;
    n->right = NULL;
    strcpy(n->cusId, customId);
    n->totalPrice = price;
    return n;
}

int total_orders = 0, revenue = 0;
BST_customId* insertCus(BST_customId* root, char* cusId, int price) {
    if (!root) {
        total_orders += 1;
        revenue += price;
        return makeNode_cus(cusId, price);
    }
    
    int cmp = strcmp(cusId, root->cusId);
    if (cmp == 0) {
        total_orders += 1;
        revenue += price;
        root->totalPrice += price;
        return root;
    }

    if (cmp < 0)  
        root->left = insertCus(root->left, cusId, price);
    else 
        root->right = insertCus(root->right, cusId, price);
    
    return root;
}

BST* makeNode(char* cusId, char* shopId, int price) {
    BST* n = (BST*)malloc(sizeof(BST));
    n->left = NULL;
    n->right = NULL;
    strcpy(n->shopId, shopId);
    n->total_revenue = price;
    n->customers = makeNode_cus(cusId, price);
    return n;
}

BST* build(BST* root, char* cusId, char* shopId, int price, int time) {
    if (!root) {
        total_orders += 1;
        revenue += price;
        return makeNode(cusId, shopId, price);
    }
    
    int cmp = strcmp(shopId, root->shopId);
    if (cmp == 0) {
        root->customers = insertCus(root->customers, cusId, price);
        root->total_revenue += price;
        return root;
    }

    if (cmp < 0)  
        root->left = build(root->left, cusId, shopId, price, time);
    else 
        root->right = build(root->right, cusId, shopId, price, time);
    
    return root;
}

// revenue of a shop
int find_total_price_customers(BST_customId* root) {
    if (!root) 
        return 0;
    
    int left = find_total_price_customers(root->left);
    int right = find_total_price_customers(root->right);

    return root->totalPrice + left + right;
}
int findReven_shopID(BST* root, char* shopId) {
    if (!root)
        return 0;
    
    int cmp = strcmp(shopId, root->shopId);
    if (cmp == 0) {
        return find_total_price_customers(root->customers);
    }

    if (cmp < 0)  
        return findReven_shopID(root->left, shopId);
    else 
        return findReven_shopID(root->right, shopId);
}

// find total price of a shop and one cus
int find_price_a_cus(BST_customId* root, char* cusId) {
    if (!root)
        return 0;
    
    int cmp = strcmp(cusId, root->cusId);
    if (cmp == 0) {
        return root->totalPrice;
    }

    if (cmp < 0)  
        return find_price_a_cus(root->left, cusId);
    else 
        return find_price_a_cus(root->right, cusId);
}
int findReven_shopID_cusId(BST* root, char* shopId, char* cusId) {
    if (!root)
        return 0;
    
    int cmp = strcmp(shopId, root->shopId);
    if (cmp == 0) {
        return find_price_a_cus(root->customers, cusId);
    }

    if (cmp < 0)  
        return findReven_shopID_cusId(root->left, shopId, cusId);
    else 
        return findReven_shopID_cusId(root->right, shopId, cusId);
    
    return 0;
}

int findReven_shopID_two(BST* root, char* shopId) {
    if (!root)
        return 0;
    
    int cmp = strcmp(shopId, root->shopId);
    if (cmp == 0) {
        return root->total_revenue;
    }

    if (cmp < 0)  
        return findReven_shopID_two(root->left, shopId);
    else 
        return findReven_shopID_two(root->right, shopId);
}

// clean
void cleanup_cus(BST_customId* root) {
    if (!root) 
        return;
    
    cleanup_cus(root->left);
    cleanup_cus(root->right);
    free(root);
}

void cleanup(BST* root) {
    if (!root) 
        return;
    
    cleanup(root->left);
    cleanup(root->right);
    cleanup_cus(root->customers);
    free(root);
}

BST* root = NULL;

