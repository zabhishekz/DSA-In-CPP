map<int, pair<int,int>> m;
void topview(node*root, int d, int h){
    if(root == NULL){
        return;
    }
    if(m[d].count == 0){
        m[d].second = h;
        m[d].first = root->data;
    }
    if(m[d].secind <= h){
        m[d].second = h;
        m[d].first = root->data;
    }
    topview(root-Left, d-1, h+1);
    topview(root-Left, d+1, h+1);
}

topview(root,0,0);