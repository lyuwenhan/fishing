#ifndef LANG_ANY
#define LANG_ANY
#define LANG_EN
#define LANG EN
#define m_main "1.Start fishing, 2.Enter shop, 3.Setting, 4.Lucky Draw, 5.Challenging, 6.Exit."
#define m_did "Challenge Completed"
#define chp_suc "Load succeeded"
#define chp_nouser "Incorrect username or password"
#define chp_login "Login"
#define chp_regi "Sign up"
#define chp_un "Username: "
#define chp_invalid "Invalid Username"
#define chp_pwd "Password: "
#define chp_repwd "Confirm password: "
#define chp_pwdng "Passwords do not match"
#define chp_yesuser "User already exists"
#define chp_regigood "Successfully registered"
#define chp_main "1.Login, 2.Sign up, 3.Exit"
#define fi_wea {"Rain", "Snow", "Sunny     ", "Overcast  ", "Cloudy    ", "Fog       "}
#define fi_big {"", "   Light ", "Moderate ", "   Heavy "}
#define fi_type {"Rotten ", "Common ", "Amethyst ", "L.Lazuli ", "Gold ", "Emerald ", "Diamond "}
#define fi_got "You caught a(n) "
#define fi_bf "Big "
#define fi_eaten "fish\033[m. You ate it because you were hungry"
#define fi_price "fish\033[m, worth $"
#define fi_inaqua "Do you want to put it into the aquarium?"
#define fi_shi "Screen height must be at least 20 rows"
#define fi_sw "Screen width must be at least 51 columns"
#define fi_sn "Current size: "
#define fi_hi " rows"
#define fi_w " columns"
#define fi_allfi "Total fish caught: "
#define fi_nowwea " Current weather: "
#define fi_getgan "Rod Shop"
#define fi_nowgan "Current rod: "
#define fi_gan "rod"
#define fi_no "None"
#define fi_exit "7.Exit"
#define fi_aq "Aquarium"
#define fi_aqtip "Tip: You can only earn aquarium profits while in the aquarium"
#define fi_aexit "1.Exit"
#define fi_f "fish: "
#define fi_azhi "fish\033[m"
#define fi_aget "You’ve gained $"
#define fi_aget2 " in profit"
#define fi_mfr "Raw Fish"
#define fi_mfn "Current amount: "
#define fi_azhi2 " fish"
#define fi_chi "    Fish pond: "
#define fi_raw "    Raw fish: "
#define fi_roast "    Roasted Fish: "
#define fi_no2 "    None\033[m"
#define fi_ro "Prepare roasted fish"
#define fi_f2 "fish"
#define fi_romain "Press A to decrease, D to increase, Enter to make, Backspace to exit"
#define fi_rom2 "Making roasted fish: "
#define fi_rob "Roasting..."
#define fi_rod " Done"
#define fi_rodone "Roasting finished"
#define fi_em "Eat raw fish"
#define fi_nowhun "Current hunger: "
#define fi_eraw "raw fish"
#define fi_ezhi " pcs +"
#define fi_eroast "Eat roasted fish"
#define fi_erof "roasted fish"
#define fi_nrm "1.Make food, 2.Eat raw fish, 3.Exit"
#define fi_rm "1.Make food, 2.Roast food, 3.Eat raw fish, 4.Eat roasted fish, 5.Exit"
#define fi_sum1 "Pollution is full. Most fish died due to illness.\033[m"
#define fi_sum2 "1.Clean the fishpond"
#define fi_sum3 "1.Start fishing, 2.Clean the pond, 3.Buy a fishing rod, 4.View the aquarium, 5.Prepare food, 6.Sell all, 7.Sell all and exit"
#define fi_sum4 "Current rod: "
#define fi_sum5 "Current pollution: "
#define fi_scl "    Freshness:"
#define fi_ncl "No cleaning needed"
#define fi_cl "1.Clean, 2.Exit"
#define fi_iscl "Current pollution: "
#define fi_clbcnt "Cleaning supplies: "
#define fi_clm1 "1.Buy cleaning supplies and clean, 2.Exit"
#define fi_cldt "Current pollution: "
#define fi_clji "Cleaning supplies: "
#define fi_clbuy "    Cost: $20, Your money: $"
#define fi_mnng "Not enough money"
#define fi_clok "Cleaning completed"
#define fi_nwt "Please buy an aquarium before viewing"
#define fi_wait "Estimated remaining time"
#define fi_egg "Egg Fish (Big Gold fish)\033[m, worth $"
#define fi_fish(big, type) ((big) + (type))
#define fi_status "Current Status: "
#define fi_statuses {"Casting the rod", "Waiting", "Fish approaching", "Reeling in", "Fish got off"}
#define fi_si "Press E to enter minimal mode"
#define fi_nsi "Press E exit minimal mode"
#define press_enter_continue "(Press Enter to continue)"
#define fun_choose {"Please choose a starting skill", "1.Delicious Bait, 2.Rare Treasures, 3.Secure Safety Rope, 4.Powerful Cleaner, 5.Popeye the Sailor, 6.Long Line for Big Fish, 7.Poor Family", "Delicious Bait:", "    Hooking speed becomes 1.5× of the original", "Rare Treasures:", "    Fish prices become 2× of the original", "Secure Safety Rope:", "    Slip-off chance is reduced from 50% to 10%", "Powerful Cleaner:", "    Start with 1 cleaner, and cleaner effectiveness is doubled", "Popeye the Sailor:", "    Casting speed changes from 1× to 2×", "Long Line for Big Fish:", "    Big fish chance changes from 20% to 40%", "Poor Family:", "    None"}
#define fun_schoose "Please choose your output speed"
#define fun_s1 "This is Slow Mode"
#define fun_s2 "This is Normal Mode"
#define fun_s3 "This is Fast Mode"
#define st_speed {"", "Slow Mode", "Normal Mode", "Fast Mode"}
#define st_speeds "1.Slow Mode, 2.Normal Mode, 3.Fast Mode"
#define st_m "1.Edit output speed, 2.Exit"
#define st_m2 "Current output speed: "
#define pk_in "Do you want to enter parkour mode?"
#define pk_tip1 "Use 'W' or Space to jump, press 'R' to respawn, press Backspace to exit."
#define pk_ok "You have completed the challenge and earned $500!"
#define pk_die "You died"
#define pk_rb "Do you want to respawn?"
#define pk_tip2 "Use 'WASD' to swim, press 'R' to respawn, press Backspace to exit."
#define story_m {"In the year 2136, the global icebergs had melted.", "Sea levels rose significantly.", "Most cities were submerged.", "You are now stranded on a small island, waiting for rescue.", "You survive each day by fishing."}
#define be_1 {{"Introduction", {"You are the hero of this world.", "You must defeat the evil dragon through your efforts.", "Along the way, you will meet many allies", "And many traps."}, {"Start"}, {""}, {1}},\
{"", {"You wake up in your bed.", "What do you want to do?"}, {"Eat breakfast", "Go outside", "Sleep a bit more"}, {"You ate breakfast", "", "You lay back in bed"}, {-1, 2, -2}},\
{"", {"You step outside onto the road.", "What do you want to do?"}, {"Go back and eat breakfast", "Go back to sleep", "Go to the blacksmith"}, {"You went back and ate breakfast", "You went back and lay in bed", "You headed to the blacksmith"}, {-1, -2, 3}},\
{"Blacksmith", {"You arrive at the blacksmith.", "Blacksmith: I heard you're going to fight the dragon.", "Blacksmith: You’ll need a proper weapon.", "Blacksmith: Tell me what you need.", "Blacksmith: Maybe I can help."}, {"Leave", "Make a weapon"}, {"You left the blacksmith", ""}, {2, 4}},\
{"Blacksmith", {"Blacksmith: What kind of weapon do you want?"}, {"A longsword"}, {"You received a longsword"}, {5}},\
{"", {"It’s time to set out."}, {"Take the small path east", "Take the wide road west"}, {"", ""}, {6, 14}},\
{"", {"You walk eastward", "You encounter an inn."}, {"Go inside to rest", "Leave"}, {"You entered the inn and rested", "You set up a tent and slept on the street"}, {10, 9}},\
{"", {"You walk eastward", "You encounter an inn."}, {"Go inside to rest", "Leave"}, {"You entered the inn and rested", ""}, {8, 12}},\
{"Died", {"You were assassinated in the inn."}, {"Rebirth"}, {""}, {1}},\
{"Died", {"You froze to death on the roadside."}, {"Rebirth"}, {""}, {1}},\
{"", {"You continue east", "You meet a merchant."}, {"Buy food", "Leave"}, {"You stocked up on food", ""}, {7, 11}},\
{"Died", {"You died of hunger on the roadside."}, {"Rebirth"}, {""}, {1}},\
{"", {"You encounter a temple."}, {"Enter", "Leave"}, {"", ""}, {13, 11}},\
{"Temple", {"You entered the temple.", "You focused on studying Buddhism.", "Eventually you became a Buddha.", "You forgot your mission."}, {"Rebirth"}, {""}, {1}},\
{"", {"You walk west", "You find another inn."}, {"Go inside to rest", "Leave"}, {"You entered the inn and rested", ""}, {15, 11}},\
{"Inn", {"You hear voices downstairs."}, {"Eavesdrop", "Sleep"}, {"", ""}, {16, 8}},\
{"Inn", {"You overhear the innkeeper plotting to steal your wallet."}, {"Escape through the window", "Fight the innkeeper"}, {"", ""}, {17, 18}},\
{"Died", {"You died from the fall."}, {"Rebirth"}, {""}, {1}},\
{"Inn", {"You defeated the innkeeper."}, {"Leave"}, {""}, {19}},\
{"", {"There are two roads ahead."}, {"Take the southern road", "Take the northern path"}, {"", ""}, {20, 23}},\
{"", {"You head down the southern road.", "You find a fork."}, {"Continue south", "Board the ship to the west"}, {"", "You boarded the ship"}, {21, 22}},\
{"Rome", {"All roads lead to Rome.", "You’ve arrived in Rome."}, {"Rebirth"}, {""}, {1}},\
{"America", {"You set sail on a great voyage.", "You discovered the American continent."}, {"Rebirth"}, {""}, {1}},\
{"", {"You take the northern path.", "You discover a cave."}, {"Enter the cave", "Leave"}, {"You entered the cave", ""}, {24, 25}},\
{"Cave", {"You find a mound of dirt in the cave.", "You begin digging.", "You discovered the world’s first complete Neanderthal skull."}, {"Rebirth"}, {""}, {1}},\
{"", {"You found the dragon's lair."}, {"Enter", "Go home for food", "Go home to sleep"}, {"You entered the dragon’s lair", "", ""}, {26, -3, -4}},\
{"Dragon's Lair", {"You arrive at the dragon’s lair."}, {"Fight the dragon", "Go home for food", "Go home to sleep"}, {"You entered the dragon’s lair", "", ""}, {27, -3, -4}},\
{"Dragon's Lair", {"You defeated the dragon!"}, {"Look for dragon egg"}, {""}, {28}},\
{"Dragon's Lair", {"You found a dragon egg."}, {"Destroy the egg", "Incubate the egg", "Go home for food", "Go home to sleep"}, {"", "", "", ""}, {32, 29, -3, -4}},\
{"Dragon's Lair", {"You started incubating the egg.", "A baby dragon hatched."}, {"Eat it", "Let it go"}, {"", ""}, {30, 31}},\
{"Dragon's Lair", {"You were killed by the baby dragon."}, {"Rebirth"}, {""}, {1}},\
{"Dragon's Lair", {"You completed your mission."}, {"Exit"}, {""}, {-5}},\
{"Dragon's Lair", {"You completed your mission."}, {"Exit"}, {""}, {-5}}}
#define be_2 "Hidden Reward Unlocked: All Roads Lead to Rome"
#define be_3 "Hidden Reward Unlocked: Lost on the Way"
#define be_4 "Hidden Reward Unlocked: Columbus's Voyage"
#define be_5 "Hidden Reward Unlocked: Pleasant Surprise"
#define be_6 "Hidden Reward Unlocked: Archaeologist"
#define be_7 "Hidden Reward Unlocked: Devoted to Buddhism"
#define be_8 "Hidden Reward Unlocked: Ascended to Immortality"
#define be_9 "Hidden Reward Unlocked: Delicious Indeed"
#define be_10 "Hidden Reward Unlocked: Stay True to Your Original Aspiration"
#define be_11 "Hidden Reward Unlocked: Keep the Mission in Mind"
#define be_12 "Hidden Reward Unlocked: That Bed is So Soft"
#define be_13 "Hidden Reward Unlocked: Sleeping Feels the Best"
#define be_14 "Hidden Reward Unlocked: Man Lives on Food"
#define be_15 "Hidden Reward Unlocked: Escaped from the Starving Ghost Realm"
#define be_16 "Hidden Reward Unlocked: What a Virtuous Hui! Eating simply, living in poverty, yet staying joyful."
#define be_17 "Hidden Reward Unlocked: You Need Sleep to Move On"
#define be_18 "Hidden Reward Unlocked: The Bed Feels Great"
#define be_19 "Hidden Reward Unlocked: Blessed by the Sleep God"
#define be_end "Finished"
#define sp_1 "1. Spin, 2. Exit"
#define sp_2 "Spin cost: 100 total fish count + 1000 coins. Current fish count: "
#define sp_3 " Current coins: "
#define sp_4 "Big Fish Bait: 20%"
#define sp_5 "Diamond Fish: 1%"
#define sp_6 "Real Fisher: 20%"
#define sp_7 "Achievement Unlocked: Swindler"
#define sp_8 "Achievement Unlocked: Short Weight"
#define sp_9 "Achievement Unlocked: Deadbeat"
#define sp_10 "Are You A Real Fisher? WRONG. YOU ARE A FISH!"
#define sp_11 "Achievement Unlocked: Who's the fish now?"
#define sp_12 "Big Fish Bait *1"
#define sp_13 "Diamond Fish *1"
#define sp_14 "Achievement Unlocked: Legendary Fish"
#define sp_15 "Better luck next time!"
#define to_1 "This is not the right place"
#define to_2 "Please press enter to exit"
#define fi_cntm 2
#endif