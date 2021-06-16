// const user = { name: 'dave', gender: 'male', age: '24' }
// const name   = user.name
// const gender = user.gender
// const age    = user.age
// console.log(name);
// console.log(gender);
// console.log(age);

// const user = { name: 'dave', gender: 'male', age: '24' }
// const { name, gender, age } = user //ek hi baar mei assign kardi vlues
// console.log(name)
// console.log(gender);
// console.log(age);

// const user = { name: 'dave', gender: 'male', age: '24' }//here we defined the user in JSON format
// const { name: n, gender: g, age: a } = user//here we assigned values to keys of JSON objext
// console.log(n)
// console.log(a);
// console.log(g);

//Default value assignment

// const user = { name: 'dave', age: '24' }
// const { name,age, gender = 'unknown' } = user//assigned default value of unknown to gender
// console.log(gender);
// console.log(name);
// console.log(age);

//Nested destructuring:

/*The examples so far have looked at extracting properties
 that are just a single level deep into an Object, but what 
 if you want to access a nested property? Destructuring allows
  us to extract values in such the same way using object literal 
  syntax. Sticking with our user example. We have expanded the name 
  property to include first_name and last_name. When initially declared 
  last_name is a nested property of the user object but using destructuring 
  we can extract this to its own variable.*/

//   const user = { 
//     name: { 
//       first_name: 'dave', 
//       last_name: 'smith' 
//     },
//     age: '24'
//   }
//   const { name: { last_name } } = user;
//   const {name:{first_name}} = user;
//   const {age} =user
//   console.log(last_name)
//   console.log(first_name)
//   console.log(age)

//array destructuring

// const colours = ["red", "blue", "green"]
// const [first, second, third] = colours
// console.log(first)
// console.log(second)
// console.log(third)

//Default values

// const colours = ["red"]
// const [first, second = "unknown", third = "Also unknown"] = colours
// console.log(first)
// console.log(second)
// console.log(third)

//Skiping values
// const colours = ["red", "blue", "green"]
// const [ , , third] = colours//here we skipped the first 2 values
// console.log(third)

//Destructuring Parametres

// function userDetails(user){
//     const name = user.name
//     const age  = user.age
//     const gender=user.gender
//   console.log(name)
//     console.log(age)
//     console.log(gender)
//   }
//   const user = {
//     name: 'dave',
//     gender: 'male',
//     age: '24'
//   }
//   userDetails(user)


                                             //The complete destructuring guide


                                            //  const student = {
                                            //     name: 'John Doe',
                                            //     age: 16,
                                            //     scores: {
                                            //         maths: 74,
                                            //         english: 63,
                                            //         science: 85
                                            //     }
                                            // };
                                            
                                            // function displaySummary(student) {
                                            //     console.log('Hello, ' + student.name);
                                            //     console.log('Your Maths score is ' + (student.scores.maths || 0));
                                            //     console.log('Your English score is ' + (student.scores.english || 0));
                                            //     console.log('Your Science score is ' + (student.scores.science || 0));
                                            // }
                                            
                                            // displaySummary(student);  
                                            
//What is object destructuring?
//Destructuring simply implies breaking down a complex structure into simpler parts.

// const student = {
//     firstname: 'Glad',
//     lastname: 'Chinda',
//     country: 'Nigeria'
// };

// // Object Destructuring
// const { firstname, lastname, country } = student;//assigning all the varibles at same time

// console.log(firstname, lastname, country); 

// Initialize local variables
// let country = 'Canada';
// let firstname = 'John';
// let lastname = 'Doe';

// const student = {
//     firstname: 'Glad',
//     lastname: 'Chinda',
//     country: 'Nigeria'
// };

// // Reassign firstname and lastname using destructuring
// // Enclose in a pair of parentheses, since this is an assignment expression
// ({ firstname, lastname } = student);

// // country remains unchanged (Canada)
// console.log(firstname, lastname, country); // Glad Chinda Canada

//Default Values

// const person = {
//     name: 'John Doe',
//     country: 'Canada'
// };

// // Assign default value of 25 to age if undefined
// const { name, country, age = 25 } = person;

// // Here I am using ES6 template literals
// console.log(`I am ${name} from ${country} and I am ${age} years old.`);


// const person = {
//     name: 'John Doe',
//     country: 'Canada'
// };

// // Assign default value of 25 to years if age key is undefined
// const { name: fullname, country: place, age: years = 25 } = person;

// // Here I am using ES6 template literals
// console.log(`I am ${fullname} from ${place} and I am ${years} years old.`);

// // I am John Doe from Canada and I am 25 years old.'

//Nested object destrucuturing

// const student = {
//     name: 'John Doe',
//     age: 16,
//     scores: {
//         maths: 74,
//         english: 63
//     }
// };

// // We define 3 local variables: name, maths, science
// const { name, scores: {maths, science = 50} } = student;//assigned default value of 50 to science

// console.log(`${name} scored ${maths} in Maths and ${science} in Elementary Science.`);

// //Array destructuring
// const rgb = [255, 200, 0];

// // Array Destructuring
// const [red, green, blue] = rgb;

// console.log(`R: ${red}, G: ${green}, B: ${blue}`); // R: 255, G: 200, B: 0

//Swapping variables

/*One very nice application of array destructuring is in swapping local variables.
 Imagine you are building a photo manipulation app and you want to be able to swap
  the height and width dimensions of a photo when the orientation of the photo is 
  switched between landscape and portrait. The old-fashioned way of doing this will 
  look like the following.*/

//   let width = 300;
// let height = 400;
// const landscape = true;

// console.log(`${width} x ${height}`); // 300 x 400

// if (landscape) {
//     // An extra variable needed to copy initial width
//     let initialWidth = width;

//     // Swap the variables
//     width = height;
  
//     // height is assigned the copied width value
//     height = initialWidth;

//     console.log(`${width} x ${height}`); // 400 x 300
// }

// //ES6 approach to implement this
// let width = 300;
// let height = 400;
// const landscape = true;

// console.log(`${width} x ${height}`); // 300 x 400

// if (landscape) {
//     // Swap the variables
//     [width, height] = [height, width];
  
//     console.log(`${width} x ${height}`); // 400 x 300
// }

//Nested array destructuring:
// const color = ['#FF00FF', [255, 0, 255], 'rgb(255, 0, 255)'];

// // Use nested destructuring to assign red, green and blue
// const [hex, [red, green, blue]] = color;

// console.log(hex, red, green, blue); // #FF00FF 255 0 255

/*Rest items
Sometimes you may want to assign some items
 to variables, while ensuring that the remaining 
 items are captured (assigned to another local variable).
  The new rest parameter syntax (...param) added in ES6 
  can be used with destructuring to achieve this. Here is a quick example.*/

 
// const rainbow = ['red', 'orange', 'yellow', 'green', 'blue', 'indigo', 'violet'];

// // Assign the first and third items to red and yellow
// // Assign the remaining items to otherColors variable using the spread operator(...)
// const [red,, yellow, ...otherColors] = rainbow;

// console.log(otherColors); // ['green', 'blue', 'indigo', 'violet'] 

//Clonning arrays
/*
In JavaScript, arrays are reference types and hence they are assigned by
 reference instead of being copied. So in the following snippet, 
 both the rainbow and the rainbowClone variables point to the same
  array reference in memory and hence any change made to rainbow is
   also applied to rainbowClone and vice-versa.*/
 
//    const rainbow = ['red', 'orange', 'yellow', 'green', 'blue', 'indigo', 'violet'];
//    const rainbowClone = rainbow;
   
//    // Both rainbow and rainbowClone point to the same
//    // array reference in memory, hence it logs (true)
//    console.log(rainbow === rainbowClone); // true
   
//    // Keep only the first 3 items and discard the rest
//    rainbowClone.splice(3);
   
//    // The change on rainbowClone also affected rainbow
//    console.log(rainbow); // ['red', 'orange', 'yellow']
//    console.log(rainbowClone); // ['red', 'orange', 'yellow']const rainbow = ['red', 'orange', 'yellow', 'green', 'blue', 'indigo', 'violet'];
//    const rainbowClone = rainbow;
   
//    // Both rainbow and rainbowClone point to the same
//    // array reference in memory, hence it logs (true)
//    console.log(rainbow === rainbowClone); // true
   
//    // Keep only the first 3 items and discard the rest
//    rainbowClone.splice(3);
   
//    // The change on rainbowClone also affected rainbow
//    console.log(rainbow); // ['red', 'orange', 'yellow']
//    console.log(rainbowClone); // ['red', 'orange', 'yellow']  

//function parametre destructuring

const student = {
    name: 'John Doe',
    age: 16,
    scores: {
        maths: 74,
        english: 63,
        science: 85
    }
};

// Without Destructuring
function displaySummary(student) {
    console.log('Hello, ' + student.name);
    console.log('Your Maths score is ' + (student.scores.maths || 0));
    console.log('Your English score is ' + (student.scores.english || 0));
    console.log('Your Science score is ' + (student.scores.science || 0));
}

// With Destructuring
function displaySummary({name, age,scores: { maths = 0, english = 0, science = 0 }}) { //here = is the default values which we assigned
    console.log('Hello, ' + name);
    console.log('Your Maths score is ' + maths);
    console.log('Your English score is ' + english);
    console.log('Your Science score is ' + science);
    console.log(age);
}

displaySummary(student);