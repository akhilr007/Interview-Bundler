struct Node {

	Node* links[26];
	bool flag;

	bool containsKey(char ch){
		return links[ch-'a'] != NULL;
	}

	void insert(char ch, Node* node){
		links[ch-'a'] = node;
	}

	Node* get(char ch){
		return links[ch-'a'];
	}

	void setEnd(){
		flag = true;
	}

	bool isEnd(){
		return flag;
	}
};

class Trie {

private:
	Node* root;

public:

	Trie(){
		root = new Node();
	}

	// tc -> O(len of word)
	void insert(string word){

		Node* node = root;

		for(int i=0; i<word.length(); i++){

			if(!node->containsKey(word[i])){

				node->insert(word[i], new Node());
			}

			node = node->get(word[i]);
		}

		node->setEnd();
	}

	// tc -> O(len of word)
	bool search(string word){

		Node* node = root;

		for(int i=0; i<word.length(); i++){

			if(!node->containsKey(word[i])){
				return false;
			}

			node = node->get(word[i]);
		}

		return node->isEnd();
	}

	// tc -> O(len of word)
	bool startsWith(string word){

		Node* node = root;

		for(int i=0; i<word.length(); i++){

			if(!node->containsKey(word[i])){
				return false;
			}

			node = node->get(word[i]);
		}

		return true;
	}
};
