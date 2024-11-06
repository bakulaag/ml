// SPDX-License-Identifier: MIT
pragma solidity >=0.7.0;

contract Bank{
    mapping(address => uint) public user_account;
    mapping(address => bool) public user_exist;

    function create_account() public payable returns(string memory){
        require(user_exist[msg.sender]==false, "account already created");

        user_account[msg.sender] = msg.value;
        user_exist[msg.sender] = true;

        return "Account successfully created" ;

    }

    function deposit(uint amount) public payable returns(string memory){
        require(user_exist[msg.sender]==true, "Account not created");
        require(amount>0, "amount should be greater than Zero");

        user_account[msg.sender] += amount;
        return "deposited successfully!" ;
    }
    
    function withdraw(uint amount) public payable returns(string memory){
        require(user_exist[msg.sender]==true, "Account not created");
        require(amount>0,"Amount should be greater than Zero");
        require(user_account[msg.sender]>=amount,"Amount is greater than deposited amount");

        user_account[msg.sender] -= amount;
        return "Amount withdrawn successfully!" ;

    }
    function balance() public view returns(uint){
        return user_account[msg.sender];
    }

    function Check() public view returns(bool){
        return user_exist[msg.sender];
    }
}