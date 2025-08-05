#include "../include/common.h"
#include "pa2.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 16

struct record {
/* character string terminated with ’\0’
* maximum length is 16
*/
char name[MAX_LEN];
/* a character array of 16 characters
* not-necessarily terminated with ’\0’
* a uid may contain multiple ’\0’’s
* anywhere in the character array
*/
char uid[MAX_LEN];
int age;
/* location */
struct location *loc;
/* list of posts */

struct list_posts *posts;
/* list of friends */
struct list_records *friends;
/* needed for shortest Path */
int status;
struct record *pred;
/* needed for the tree data-structure */
int height;
struct record *left;
struct record *right;
struct record *parent;
};

struct list_records {
struct record *record;
struct list_records *next;
};

struct avl_node {
    struct record *record;
    struct record *left;
    struct record *right;
};

#include<stdio.h>
#include <string.h>

// don't remove these globals
static struct record *bst_root = NULL;
static struct record *avl_root = NULL;
static size_t num_bst_nodes = 0;
static size_t num_avl_nodes = 0;

// don't modify this function
struct record *get_bst_root()
{
  return bst_root;
}

// don't modify this function
struct record *get_avl_root()
{
  return avl_root;
}

// don't modify this function
// compare two uids
// return -1 if uid1 < uid2
// return 0 if uid1 == uid2
// return 1 if uid1 > uid2
static int cmp_uid(char *uid1, char *uid2)
{
  int i;

  for (i = 0; i < MAX_LEN; i++) {
    if (uid1[i] > uid2[i]) {
      return 1;
    }
    else if (uid1[i] < uid2[i]) {
      return -1;
    }
  }
  return 0;
}

// don't modify this function
// compare two records
// we assume that uid is unique and
// there can't be two records with the 
// same uid
// return -1 if record1 < record2
// return 0 if record1 == record2
// return 1 if record1 > record2
static int cmp_record(struct record *r1, struct record *r2)
{
  return cmp_uid(r1->uid, r2->uid);
}

// don't modify this function
static void *allocate_memory(size_t size)
{
  return __mymalloc(size);
}

// don't modify this function
static void free_memory(void *ptr)
{
  __myfree(ptr);
}

// ---------------- Add your code below this line ----------------- //

// Return the total number of records in the
// BST rooted at bst_root.
size_t get_num_bst_records()
{
  return num_bst_nodes;
}

// Return the total number of records in the
// AVL tree rooted at avl_root.
size_t get_num_avl_records()
{
  return num_avl_nodes;
}

// Insert record r in the BST rooted at bst_root.
void insert_record_bst(struct record r)
{
  struct record *parent = NULL;
  struct record *current = bst_root;

  while (current != NULL) {
    parent = current;
    if (cmp_record(&r, current) < 0) {
      current = current->left;
    }
    else {
      current = current->right;
    }
  }

  struct record *new_node = (struct record *) allocate_memory(sizeof(struct record));
  memcpy(new_node, &r, sizeof(struct record));

  new_node->left = NULL;
  new_node->right = NULL;

  if (parent == NULL) {
    bst_root = new_node;
  }
  else if (cmp_record(&r, parent) < 0) {
    parent->left = new_node;
  }
  else {
    parent->right = new_node;
  }

  num_bst_nodes++;
}


// Insert record r in the AVL tree rooted at avl_root.
void insert_record_avl(struct record r)
{
    struct record *parent = NULL;
    struct record *current = avl_root;
    struct record *new_node = (struct record *) allocate_memory(sizeof(struct record));
    memcpy(new_node, &r, sizeof(struct record));

    new_node->left = NULL;
    new_node->right = NULL;

    // Find the position to insert new_node
    while (current != NULL) {
        parent = current;
        if (cmp_record(&r, current) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Insert the new_node
    if (parent == NULL) {
        avl_root = new_node;
    } else if (cmp_record(&r, parent) < 0) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    // Re-balance the AVL tree
    struct record *unbalanced_node = new_node;
    while (unbalanced_node != NULL) {
        int balance_factor = get_balance_factor(unbalanced_node);
        if (balance_factor > 1) {
            // Left-Left case
            if (get_balance_factor(unbalanced_node->left) >= 0) {
                unbalanced_node = rotate_right(unbalanced_node);
            }
            // Left-Right case
            else {
                unbalanced_node->left = rotate_left(unbalanced_node->left);
                unbalanced_node = rotate_right(unbalanced_node);
            }
        } else if (balance_factor < -1) {
            // Right-Right case
            if (get_balance_factor(unbalanced_node->right) <= 0) {
                unbalanced_node = rotate_left(unbalanced_node);
            }
            // Right-Left case
            else {
                unbalanced_node->right = rotate_right(unbalanced_node->right);
                unbalanced_node = rotate_left(unbalanced_node);
            }
        }
        unbalanced_node = unbalanced_node->parent;
    }
    num_avl_nodes++;
}


// Search the record corresponding to uid in the BST
// rooted at bst_root.
// If the record is not present, return a dummy record
// with -1 in the status field.
struct record *search_record_bst(char uid[MAX_LEN])
{
    struct record *current = bst_root;

    while (current != NULL) {
        int cmp = strcmp(current->uid, uid);
        if (cmp == 0) {
        return current;
        } else if (cmp < 0) {
        current = current->right;
        } else {
        current = current->left;
        }
    }

    struct record *dummy_record;
    memset(&dummy_record, 0, sizeof(struct record));
    dummy_record->status = -1;
    return dummy_record;
}

// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// Return the head of the linked list of friends
// of the user with uid uid in the BST rooted at bst_root.
// If the corresponding record doesn't exist, return NULL.
struct list_records *get_friends_list_bst(char uid[MAX_LEN])
{
struct record *current = bst_root;

while (current != NULL) {
int cmp = strcmp(current->uid, uid);
if (cmp == 0) {
return current->friends;
} else if (cmp < 0) {
current = current->right;
} else {
current = current->left;
}
}

return NULL;
}

// Delete the record (say n) corresponding to uid from the BST.
// Remove n from the lists of friends of other records
// and release the memory for the linked list nodes.
// Release memory for all the nodes in the list of friends of n.
// Return a copy of the value of the deleted node.
// If the node is not present, return a dummy record
// with -1 in the status field.
struct record delete_record_bst(char uid[MAX_LEN])
{
    struct record *current = bst_root;
    struct record *parent = NULL;

    while (current != NULL) {
        int cmp = strcmp(current->uid, uid);
        if (cmp == 0) {
            // Found the node to delete
            if (parent == NULL) {
                // Deleting the root node
                bst_root = delete_node(current);
            } else {
                if (parent->left == current) {
                    parent->left = delete_node(current);
                } else {
                    parent->right = delete_node(current);
                }
            }
            return *current;
        } else if (cmp > 0) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    // If node not found, return a dummy record with -1 in the status field
    struct record dummy_record = { .status = -1 };
    return dummy_record;
}

struct record search_record_avl(char uid[MAX_LEN])
{
    struct record *current = avl_root;

    while (current != NULL) {
        int cmp = strcmp(current->uid, uid);
        if (cmp == 0) {
            // Found the node
            return *current;
        } else if (cmp > 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // If node not found, return a dummy record with -1 in the status field
    struct record dummy_record = { .status = -1 };
    return dummy_record;
}

struct list_records *get_friends_list_avl(char uid[MAX_LEN])
{
    struct record *current = avl_root;

    while (current != NULL) {
        int cmp = strcmp(current->uid, uid);
        if (cmp == 0) {
            // Found the node, return the head of the linked list of friends
            return current->friends;
        } else if (cmp > 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // If node not found, return NULL
    return NULL;
}

struct record delete_record_avl(char uid[MAX_LEN])
{
    struct record *current = avl_root;
    struct record *parent = NULL;

    while (current != NULL) {
        int cmp = strcmp(current->uid, uid);
        if (cmp == 0) {
            // Found the node to delete
            if (parent == NULL) {
                // Deleting the root node
                avl_root = delete_node_avl(current);
            } else {
                if (parent->left == current) {
                    parent->left = delete_node_avl(current);
                } else {
                    parent->right = delete_node_avl(current);
                }
            }
            // Remove node from lists of friends of other records
            remove_node_from_friends_lists(current);
            // Release memory for all nodes in the list of friends of n
            destroy_list_records(current->friends);
            // Return a copy of the value of the deleted node
            return *current;
        } else if (cmp > 0) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    // If node not found, return a dummy record with -1 in the status field
    struct record dummy_record = { .status = -1 };
    return dummy_record;
}

// Release memory for all BST nodes and their lists of friends.
// Make bst_root points to an empty tree.
void destroy_bst()
{
    while (bst_root != NULL) {
        struct record *temp = bst_root;
        bst_root = bst_root->left;
        destroy_list(temp->friends);
        free(temp);
    }
}

// Release memory for all AVL nodes and their lists of friends.
// Make avl_root points to an empty tree.
void destroy_avl()
{
    if (avl_root != NULL) {
        destroy_avl_helper(avl_root);
        avl_root = NULL;
    }
}

// Recursive helper function for destroy_avl.
void destroy_avl_helper(struct avl_node *node)
{
    if (node != NULL) {
        destroy_avl_helper(node->left);
        destroy_avl_helper(node->right);
        destroy_list(node->record->friends);
        free(node->record);
        free(node);
    }
}

// Make users with uids uid1 and uid2 in the BST rooted at bst_root
// friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// To make the user with record A a friend of the user with record B, 
// add A to B's list of friends and add B to A's list of friends.
// Return 1 if uid1 and uid2 are already friends before this call.
// Return 0 if they become friends during this call.
int make_friends_bst(char uid1[MAX_LEN], char uid2[MAX_LEN])
{
    struct record *record1 = search_record_bst(uid1);
    if (record1 == NULL) {
        return -1; // uid1 doesn't exist
    }
    struct record *record2 = search_record_bst(uid2);
    if (record2 == NULL) {
        return -2; // uid2 doesn't exist
    }

    // Check if uid1 and uid2 are already friends
    struct list_records *friend_list = record1->friends;
    while (friend_list != NULL) {
        if (strcmp(friend_list->record->uid, uid2) == 0) {
            return 1; // uid1 and uid2 are already friends
        }
        friend_list = friend_list->next;
    }

    // Add uid2 to uid1's list of friends
    struct list_records *new_friend = (struct list_records*)malloc(sizeof(struct list_records));
    new_friend->record = record2;
    new_friend->next = record1->friends;
    record1->friends = new_friend;

    // Add uid1 to uid2's list of friends
    new_friend = (struct list_records*)malloc(sizeof(struct list_records));
    new_friend->record = record1;
    new_friend->next = record2->friends;
    record2->friends = new_friend;

    return 0; // uid1 and uid2 become friends
}

// Make users with uids uid1 and uid2 in the AVL tree rooted at avl_root
// friends of each other if they aren't already friends.
// The friends field in "struct record" stores the
// head of the linked list of friends of a given user.
// To make the user with record A a friend of the user with record B, 
// add A to B's list of friends and add B to A's list of friends.
//
int make_friends_avl(char uid1[MAX_LEN], char uid2[MAX_LEN])
{
    // Find the records corresponding to uid1 and uid2
    struct record *record1 = find_record_avl(avl_root, uid1);
    struct record *record2 = find_record_avl(avl_root, uid2);

    // Return 1 if they are already friends
    if (are_friends(record1, record2))
        return 1;

    // Otherwise, add each other to their friends list
    struct list_records *new_friend = (struct list_records *)malloc(sizeof(struct list_records));
    strcpy(new_friend->record->uid, uid2);
    new_friend->next = NULL;

    struct list_records *current = record1->friends;
    while (current != NULL) {
        if (strcmp(current->record->uid, uid2) == 0) {
            // uid1 is already a friend of uid2
            free(new_friend);
            return 1;
        }
        current = current->next;
    }
    new_friend->next = record1->friends;
    record1->friends = new_friend;

    new_friend = (struct list_records *)malloc(sizeof(struct list_records));
    strcpy(new_friend->record->uid, uid1);
    new_friend->next = NULL;

    current = record2->friends;
    while (current != NULL) {
        if (strcmp(new_friend->record->uid, uid1) == 0) {
            // uid2 is already a friend of uid1
            free(new_friend);
            return 1;
        }
        current = current->next;
    }
    new_friend->next = record2->friends;
    record2->friends = new_friend;

    // Update the AVL tree
    avl_root = avl_insert(avl_root, record1);
    avl_root = avl_insert(avl_root, record2);

    return 0;
}