//
//  main.swift
//  EggQuiz
//
//  Created by Devin on 7/02/17.
//  Copyright © 2017 Devin. All rights reserved.
//



public protocol IRule{
    func isMatch(numberOfEgg:Int)->Bool
}

class Rule1 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return true
    }
}

class Rule2 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 2 == 1
    }
}

class Rule3 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 3 == 0
    }
}

class Rule4 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 4 == 1
    }
}

class Rule5 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 5 == 5 - 1
    }
}

class Rule6 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 6 == 3
    }
}

class Rule7 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 7 == 0
    }
}
class Rule8 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 8 == 1
    }
}
class Rule9 : IRule{
    func isMatch(numberOfEgg: Int) -> Bool {
        return numberOfEgg % 9 == 0
    }
}

var rules: [IRule] = [Rule1(), Rule2(), Rule3(), Rule4(),
        Rule5(), Rule6(), Rule7(), Rule8(), Rule9()]

for i in 1...1000000{
    var results = rules.map({
        (rule:IRule) -> Int in
        return rule.isMatch(numberOfEgg: i) ? 0 : 1
    })
    if results.reduce(0, +) == 0 {
        print("Result: ", i)
        break
    }

}

