#ifndef QUEUE_H
#define QUEUE_H

/**
 * @file queue.h
 * @author Arthur Pechenkin
 * @brief Implementation of a queue data structure using linked lists.
 *
 * This is a C++ header file that defines a queue class, which is a data
 * structure that allows elements to be added at the end and removed from the
 * front. The class has the following properties and methods: `front`: A pointer
 * to the node at the front of the queue. `rear`: A pointer to the node at the
 * rear of the queue. The class has the following methods: `Queue()`: The
 * constructor, which initializes the queue with empty.
 * `~Queue()`: The destructor, which deletes all nodes in the queue and sets
 * `front` and `rear` to null. `enqueue(int value)`: Inserts a new node at the
 * back of the queue with the given value. If the queue is empty, the new node
 * becomes the front and rear of the queue. `dequeue()`: Removes the node at the
 * front of the queue and returns its data. If the queue is empty, it returns
 * -1. `isEmpty()`: Returns true if the queue is empty, false otherwise. The
 * class also includes a `Node` struct, which represents a node in the queue.
 * Each node has a `data` field and a `next` field that points to the next node
 * in the queue. The file includes a comment at the top that provides a brief
 * description of the program, the author, version, date, and copyright
 * information.
 * @version 0.1
 * @date 01-04-2024
 *
 * @copyright Copyright (c) 2024 Arthur Pechenkin. All rights reserved.
 *
 */

#include <iostream>

class Queue {
private:
  struct Node {
    int data;
    Node *next;
  };

  Node *front;
  Node *rear;

public:
  /**
   * @brief constructs an empty queue
   */
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  /**
   * @brief deconstructor for the queue class
   *
   * this function will delete all nodes in the queue and set the front and rear
   * to null
   */
  ~Queue() {
    while (!isEmpty()) {
      dequeue();
    }
  }

  /**
   * @brief inserts a new node at the back of the queue
   *
   * @param value the data to be inserted
   *
   * This function creates a new node with the given value and inserts it at the
   * back of the queue. If the queue is empty, the new node becomes the front
   * and rear of the queue.
   */
  void enqueue(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
      front = newNode;
      rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  /**
   * @brief removes the node at the front of the queue
   *
   * This function removes the node at the front of the queue and returns its
   * data. If the queue is empty, it returns -1.
   *
   * @return int the data of the node at the front of the queue, or -1 if the
   * queue is empty
   */
  int dequeue() {
    if (isEmpty()) {
      std::cout << "Queue is empty!" << std::endl;
      return -1;
    }

    int value = front->data;
    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr) {
      rear = nullptr;
    }

    return value;
  }

  /**
   * @brief Checks if the queue is empty
   *
   * @return true if the queue is empty, false otherwise
   */
  bool isEmpty() { return front == nullptr; }
};

#endif // QUEUE_H
