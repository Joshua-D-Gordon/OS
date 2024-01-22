# OS Exc1
## Question 1
Our IDs end in 3 and 4, so we did Bag A and B.
### Bug A:

1. Compile the program without debugging: <br />
    <img width="251" alt="צילום מסך 2024-01-22 172024" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/4c3ba0f8-991e-43a5-9d8a-8710af3d023c">
    <br />
    Compile the program with debug: <br />
    <img width="226" alt="צילום מסך 2024-01-22 175757" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/6d4bfda0-9bf1-4e8f-bbe1-e0f48cf74f10">

2. Running the program without debugging: <br />
  <img width="242" alt="צילום מסך 2024-01-22 172209" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/387dfaf1-626c-4d01-a7f8-e85498a0a64e"> <br />
  Running the program with debug:
  <br /><img width="242" alt="צילום מסך 2024-01-22 175831" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/8b46900b-cf33-43df-905d-c6e92075e5c1">

4. To enable the display of the core, you must first run: `ulimit -c unlimited`
    <br />
   <img width="294" alt="צילום מסך 2024-01-22 174517" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/e552375e-daa6-405b-9475-c2201ff88929">
   <br />
  Then you need to enter: `/var/lib/apport/coredump` <br />
  <img width="589" alt="צילום מסך 2024-01-22 174619" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/669cbb10-0952-4d88-ad01-f87df9134b5d"> <br />
  Then we will take the file found here, and copy it to the project folder:

  <img width="614" alt="צילום מסך 2024-01-22 174818" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/8074ba73-144d-46d4-82d7-a1f1cc484d9f">  <br /> 
  Let's change the file name to core1: <br />
  <img width="481" alt="צילום מסך 2024-01-22 175021" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/2e1ba39b-c4d9-42bd-85e3-09c71c6dc7d2">

4. Open core using gdb:
   Input without debug: <br />
   <img width="374" alt="צילום מסך 2024-01-22 180416" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/e5c312ba-f0f8-46fe-8a87-63d52bf408c8"> <br />
   Input with debug: <br />
  <img width="381" alt="צילום מסך 2024-01-22 180707" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/c62676b0-1f6d-4bae-bf41-ac5592ea9e56"> <br />
  You can see that when running without debug the program says (No debugging symbols found in main) which means there is no appropriate debug symbol, compared to when running debug is not listed. <br />
  In addition, when running with debug, the line where the error is found is present compared to when running without debug where the line where the error is found does not exist.

5. To find the relevant line, you need to run gdb with the debugger, then at the end of the initial caption, write down exactly which line the error is in, in our case, it appears on line 8.
   <br /> <img width="229" alt="צילום מסך 2024-01-22 181444" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/41743925-f48c-4d0c-b641-edbf4931c56e"> <br />

6. First we will install ddd:
   <img width="289" alt="צילום מסך 2024-01-22 181914" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/70c8b241-2d26-4446-8dd7-6e9883c5ff0e">
   To open core using a graphical debugger, you need to do the following line in Terminal: `ddd ./mainDebug` <br />

   <img width="502" alt="צילום מסך 2024-01-22 183019" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/6e8007d5-1e80-4c3d-b4fb-5d6a67657ca2"> <br /> In the graphical debugger, you can add breakpoints and see the graphical gdb: <br />
   <img width="423" alt="צילום מסך 2024-01-22 183259" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/6f860e28-3bbb-4d37-87d0-86c1e4d89cde"> <br />

### Bug B:

1. Compile the program without debugging: <br />
    <img width="241" alt="צילום מסך 2024-01-22 183605" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/53fe79af-c4f2-47d1-9f6f-7aa87bcabb0c">
    <br />
    Compile the program with debug:
   <br />
   <img width="234" alt="צילום מסך 2024-01-22 183618" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/bd06f2a8-040d-415d-9fe0-fa8e7fb1ee8e">

2. Running the program without debugging: <br />
  <img width="232" alt="צילום מסך 2024-01-22 184236" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/873e9e2d-afb1-4e71-9a5e-8ad572e58eed"> <br />
  Running the program with debug:
  <br /> <img width="250" alt="צילום מסך 2024-01-22 184244" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/9383f153-aace-4c09-8b20-aa8b6061f0ac">


3. To enable the display of the core, you must first run: `ulimit -c unlimited`
    <br />
   <img width="294" alt="צילום מסך 2024-01-22 174517" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/e552375e-daa6-405b-9475-c2201ff88929">
   <br />
  Then you need to enter: `/var/lib/apport/coredump` <br />
  <img width="589" alt="צילום מסך 2024-01-22 174619" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/669cbb10-0952-4d88-ad01-f87df9134b5d"> <br />
  Then we will take the file found here, and copy it to the project folder:
  <img width="614" alt="צילום מסך 2024-01-22 174818" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/8074ba73-144d-46d4-82d7-a1f1cc484d9f">  <br /> 
  Let's change the file name to core1: <br />
  <img width="481" alt="צילום מסך 2024-01-22 175021" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/2e1ba39b-c4d9-42bd-85e3-09c71c6dc7d2">

4. Open core using gdb:
   Input without debug: <br />
   <img width="364" alt="צילום מסך 2024-01-22 184550" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/152f37c4-8f31-45cc-b9fb-d59d251b25f2"> <br />
   Input with debug: <br />
   <img width="364" alt="צילום מסך 2024-01-22 184550" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/e2f1b134-ae88-4b02-928c-33b8398f5c0b"> <br />
  You can see that when running without debug the program says (No debugging symbols found in main) which means there is no appropriate debug symbol, compared to when running debug is not listed. <br />
  In addition, when running with debug, the line where the error is found is present compared to when running without debug where the line where the error is found does not exist.

5. To find the relevant line, you need to run gdb with the debugger, then at the end of the initial caption, write down exactly which line the error is in, in our case, it appears on line 10.
   <br /> <img width="401" alt="צילום מסך 2024-01-22 184752" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/62c50012-2ec2-4a09-9c2b-85628fa06abf">
 <br />

6. To open core using a graphical debugger, you need to do the following line in Terminal: `ddd ./mainfourDebug` <br />
  <img width="502" alt="צילום מסך 2024-01-22 185010" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/946cf27f-4555-41c0-a830-20aa80a5bd43"> <br />   In the graphical debugger, you can add breakpoints and see the graphical gdb: <br />
  <img width="425" alt="צילום מסך 2024-01-22 185032" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/8b7267b3-a398-437d-a6fd-32c6c4abead3">

## Question 2
The program is running and working and thinking well. <br />
**We assumed that the third variable was the permit.** <br />
**In addition, we added a margin of confidence if the margin of error is up to 0.0001 then it is true.** <br /> <br />

Compilation of the program:

<img width="229" alt="צילום מסך 2024-01-22 191354" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/2055177f-ef20-49c0-a8b1-458b38c98170">

From the compilation you can see that we are using the standard math library `-lm` <br />
Running the program: <br />
<img width="217" alt="צילום מסך 2024-01-22 191700" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/93db1c3f-f916-42ea-bfff-fddb4ba2a92d">

That is, you can see that: 3,4,5 is a Pythagorean triangle, and the angles in the triangle are: 0.643501, 0.927295, 1.570796 <br />

Another run of the program, when we show that the range is met:

<img width="197" alt="צילום מסך 2024-01-22 193702" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/81878702-1e40-4542-8bec-74a6337b7542"> <br />
That is, you can see that: 3.00001,4.00001,5.00001 is a Pythagorean triangle, and the angles in the triangle are: 0.643502, 0.927296, 1.570795
<br /> <br />
Another run of the program: <br />
<img width="217" alt="צילום מסך 2024-01-22 192344" src="https://github.com/Joshua-D-Gordon/OS/assets/99357654/75c1b7ba-5908-4d12-a19c-0b1b96882063"> <br />
When we run a triple that is not Pythagorean, for example: 4,5,6 the program will return Error.

## Question 3

## Question 4

