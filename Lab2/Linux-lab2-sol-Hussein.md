# version control - lab2
### 1- Create a new project on your local machine,then push it your remote repo.

![version-control lab2-q1 p1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/66488c86-0943-4b92-ae25-83eae30d91d6)

![version-control lab2-q1 p2](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/c2ff053d-519d-4aab-8e70-73fa2c4b0f98)


### 2- Create two branches (dev & test) then create one file on each branch, and push this changes to the remote repo.

![version-control lab2-q2 p1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/0ee8124a-3a4c-4215-9b42-96d214795fe9)

![version-control lab2-q2 p2](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/5b4a19d1-a391-41c7-8c44-556aadf967b8)


### 3- Merge this changes on Master branch and then push it to your remote master branch.

![version-control lab2-q3 p1](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/1d419200-5667-4fa6-834a-7f08d3f437e9)


### 4- Tell me how to remove them locally and remotely.
# Delete branches locally
git branch -d dev
git branch -d test
# Delete branches remotely
git push origin --delete dev
git push origin --delete test

### 5- Create an annotated tag with tagname (v1.7).
git tag -a v1.7 -m "Version 1.7"

### 6- Push it to the remote repository.
git push origin v1.7

### 7- Tell me how to list tags.
git tag

![version-control lab2-q5-7](https://github.com/hussein-elmlah/ITI-Labs-Hussein-Eid/assets/147069168/4a71c933-205e-472d-bd49-76f31ad5279e)

### 8- Tell me how to delete tag locally and remotely.
# Delete local tag
git tag -d v1.7
# Delete remote tag
git push origin --delete v1.7
