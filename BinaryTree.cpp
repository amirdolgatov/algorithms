// Минимальное и максимальное значение в дереве

template<typename T>
struct Node{
	T value;
	Node<T> *right;
	Node<T> *left;
	}

template<typename T>
Node<T>* min(Node<T> *node){
	if(node->left == nullptr)
		return node;
	return min(node->left);
	}
	
template<typename T>
Node<T>* max(Node<T> *node){
	if(node->right == nullptr)
		return node;
	return max(node->right);
	}
	
// Нерекурсивные реализации MIN, MAX
 
Node<T>* min(Node<T> *node){
	while(node->left != nullptr)
		node = node->left;
	return node;
	}
	
Node<T>* max(Node<T> *node){
	while(node->right != nullptr)
		node = node->right;
	return node;
	}
	
// Выбрка (поиск)
Node<T>* search(Node<T> *node, T& data){
	if(node == nullptr)
		return node;
	if(data == node->value)
		return node;
	if(data > node->value)
		return search(node->right, data);
	if(data < node->value)
		return search(node->left, data);
	}
	
	
// Вставка элемента
Node<T>* insert(Node<T> *node, T& data){
	if(node == nullptr)
		return new Node{data};
	if(data > node->data)
		node->right = insert(node->right, data);
	if(data < node->data)
		node->left = insert(node->left, data);
	return node;
	}
	

void delete(Node<T> *head, T& data){
	
	Node<T>* node = search(head, data);
	Node<T>* deleted;
	
	if(node != nullptr){
		if(node->left || node->right)      // node is a leaf
		{
			delete node;
			node = nullptr;
		}	
		
		else if(node->left){                      
			deleted = node->left;
			node->data = deleted->data;
			node->right = deleted->right;
			node->left = deleted->left;
			delete deleted;
		}
		else if(node->right){
			deleted = node->right;
			node->data = deleted->data;
			node->right = deleted->right;
			node->left = deleted->left;
			delete deleted;
		}
		else{
			auto minNode = min(node->right);
			node->data = minNode->data;
			if(!minNode->right){
				deleted = minNode->right;
				minNode->right = minNode->right->right;
				minNode->left = minNode->right->left;
				delete deleted;
			}
			
	}
	
	
	

	
	
