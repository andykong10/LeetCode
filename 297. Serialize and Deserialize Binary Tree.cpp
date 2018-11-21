// To serialize, preorder traverse the tree, add the value of each node followed by a space to ostringstream&,
// if null node is encountered, simplly add "n " to ostringstream&.
//
// To deserialize, covert string to istringstream (so we can take advantage of in >> value is natually separated by space),
// preorder traverse the istringstream& and construct the tree.
class Codec
{

	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root)
		{
			ostringstream out;
			serialize(root, out);
			return out.str();
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(const string& data)
		{
			istringstream in(data);
			return deserialize(in);
		}

	private:

		void serialize(TreeNode* root, ostringstream& out)
		{
			if (!root)
			{
				out << "n" << " ";
				return;
			}
			
			out << root->val << " ";
			serialize(root->left, out);
			serialize(root->right, out);
		}

		TreeNode* deserialize(istringstream& in)
		{
			string value;
			in >> value;

			if (value == "n")
			{
				return nullptr;
			}

			TreeNode* root = new TreeNode(stoi(value));
			root->left = deserialize(in);
			root->right = deserialize(in);

			return root;
		}

};