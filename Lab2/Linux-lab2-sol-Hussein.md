# version control - lab2
### 1- Create a new project on your local machine,then push it your remote repo.



### 2- Create two branches (dev & test) then create one file on each branch, and push this changes to the remote repo.



### 3- Merge this changes on Master branch and then push it to your remote master branch.



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



### 8- Tell me how to delete tag locally and remotely.
# Delete local tag
git tag -d v1.7
# Delete remote tag
git push origin --delete v1.7