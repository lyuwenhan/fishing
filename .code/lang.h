#ifdef EN
#define m_main "1.Start fishing, 2.Enter shop, 3.Setting, 4.Lucky Draw, 5.Challenging, 6.Exit."
#define m_did "Challenge Completed"
#define chp_suc "Load succeeded"
#define chp_err "Checkpoint is damaged"
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
#define fi_got "You caught a(n)"
#define fi_bf "big"
#define fi_eaten "fish\033[m. You ate it because you were hungry"
#define fi_price "fish\033[m, worth $"
#define fi_inaqua "Do you want to put it into the aquarium?"
#define fi_shi "Screen height must be at least 18 rows"
#define fi_sw "Screen width must be at least 44 columns"
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
#define press_enter_continue "(Press Enter to continue)"
#define fun_choose {"Please choose a starting skill", "1.Delicious Bait, 2.Rare Treasures, 3.Secure Safety Rope, 4.Powerful Cleaner, 5.Popeye the Sailor, 6.Long Line for Big Fish, 7.Poor Family", "Delicious Bait:", "    Hooking speed becomes 1.5× of the original", "Rare Treasures:", "    Fish prices become 2× of the original", "Secure Safety Rope:", "    Slip-off chance is reduced from 50% to 10%", "Powerful Cleaner:", "    Start with 1 cleaner, and cleaner effectiveness is doubled", "Popeye the Sailor:", "    Casting speed changes from 1× to 2×", "Long Line for Big Fish:", "    Big fish chance changes from 20% to 40%", "Poor Family:", "    None"}
#define fi_egg "Egg Fish\033[m, worth $"
#define st_speed {"", "Slow", "Normal", "Fast"}
#define st_speeds "1.Slow, 2.Normal, 3.Fast"
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
#else
#define m_main "1.开始钓鱼, 2.进入商店, 3.设置, 4.抽奖, 5.挑战, 6.退出, 其他输入无效。"
#define m_did "已完成挑战"
#define chp_suc "读取成功"
#define chp_err "存档损坏"
#define chp_nouser "用户名或密码错误"
#define chp_login "登录"
#define chp_regi "注册"
#define chp_un "用户名: "
#define chp_invalid "用户名不合法"
#define chp_pwd "密码: "
#define chp_repwd "请确认密码: "
#define chp_pwdng "两次密码不一致"
#define chp_yesuser "用户已存在"
#define chp_regigood "注册成功"
#define chp_main "1.登录, 2.注册, 3.退出"
#define fi_wea {"雨    ", "雪    ", "晴      ", "阴      ", "多云    ", "雾      "}
#define fi_big {"", "小", "中", "大"}
#define fi_type {"腐烂的", "普通的", "紫水晶", "青金石", "金", "绿宝石", "钻石"}
#define fi_got "你钓到了一条"
#define fi_bf "大"
#define fi_eaten "鱼\033[m, 因饥饿已食用"
#define fi_price "鱼\033[m, 价值$"
#define fi_inaqua "是否放入水族馆"
#define fi_shi "屏幕高度需至少为18行"
#define fi_sw "屏幕宽度需至少为44列"
#define fi_sn "当前为 "
#define fi_hi " 行"
#define fi_w " 列"
#define fi_allfi "累计钓鱼数量: "
#define fi_nowwea " 当前天气: "
#define fi_getgan "鱼竿兑换"
#define fi_nowgan "当前鱼竿: "
#define fi_gan "鱼竿"
#define fi_no "暂无"
#define fi_exit "7.退出"
#define fi_aq "水族馆"
#define fi_aqtip "提示: 只有在水族馆里才能获得水族馆的收益"
#define fi_aexit "1.退出"
#define fi_f "鱼: "
#define fi_azhi "只\033[m"
#define fi_aget "你共获得 "
#define fi_aget2 "$ 的收益"
#define fi_mfr "生鱼肉"
#define fi_mfn "当前数量: "
#define fi_azhi2 " 只"
#define fi_chi "    鱼池: "
#define fi_raw "    生鱼: "
#define fi_roast "    烤鱼: "
#define fi_no2 "    暂无\033[m"
#define fi_ro "制作烤鱼"
#define fi_f2 "鱼"
#define fi_romain "按 A 减少, D 增加, 按 Enter 制作, 按 Backspace 退出"
#define fi_rom2 "制作熟鱼肉: "
#define fi_rob "烤制中"
#define fi_rod " 完成"
#define fi_rodone "烤制完成"
#define fi_em "食用生鱼肉"
#define fi_nowhun "当前饱食度: "
#define fi_eraw "生鱼"
#define fi_ezhi " 只 +"
#define fi_eroast "食用熟鱼肉"
#define fi_erof "熟鱼"
#define fi_nrm "1.制作食物, 2.食用生鱼肉, 3.退出"
#define fi_rm "1.制作食物, 2.烤制食物, 3.食用生鱼肉, 4.食用熟鱼肉, 5.退出"
#define fi_sum1 "当前污染已达极限, 大部分鱼因病死亡\033[m"
#define fi_sum2 "1.清理鱼池"
#define fi_sum3 "1.开始钓鱼, 2.清理鱼池, 3.购买钓竿, 4.查看水族馆, 5.制作食物, 6.全部卖出, 7.全部卖出并退出"
#define fi_sum4 "当前鱼竿: "
#define fi_sum5 "当前污染等级: "
#define fi_scl "    新鲜度:"
#define fi_ncl "无需清理"
#define fi_cl "1.清理, 2.退出"
#define fi_iscl "当前污染等级: "
#define fi_clbcnt "当前清洁剂个数: "
#define fi_clm1 "1.购买清洁剂并清理, 2.退出"
#define fi_cldt "当前污染等级: "
#define fi_clji "清洁剂: "
#define fi_clbuy "    购买花费: $20, 当前金币数量: $"
#define fi_mnng "金币不足"
#define fi_clok "清理完成"
#define fi_nwt "请在购买水族馆后在来查看"
#define press_enter_continue "(按Enter继续)"
#define fun_choose {"请选择开局技能", "1.美味诱饵, 2.稀世珍宝, 3.牢靠安全绳, 4.强效清洁剂, 5.大力水手, 6.放长线钓大鱼, 7.孤苦人家", "美味诱饵:", "    上钩速度变为原先的1.5倍", "稀世珍宝:", "    鱼的价格变为原先的2倍", "牢靠安全绳:", "    脱钩概率由50%变为10%", "强效清洁剂:", "    初始获得1个清洁剂, 并且清洁剂效果翻倍", "大力水手:", "    甩杆倍速由1倍变为2倍", "放长线钓大鱼:", "    大鱼概率由20%变为40%", "孤苦人家:", "    无"}
#define fi_egg "鸡蛋鱼\033[m, 价值$"
#define st_speed {"", "慢速", "普通", "急速"}
#define st_speeds "1.慢速, 2.普通, 3.急速"
#define st_m "1.更改输出速度, 2.退出"
#define st_m2 "当前输出速度: "
#define pk_in "是否进入跑酷"
#define pk_tip1 "使用w或空格进行跳跃, 按r重生, 按backspace退出"
#define pk_ok "完成挑战, 获得 $500"
#define pk_die "你阵亡了"
#define pk_rb "是否重生"
#define pk_tip2 "使用wasd进行游泳, 按r重生, 按backspace退出"
#define story_m {"2136年, 全球冰山融化了", "海平面上升了许多", "大部分城市被海平面淹没了", "你待在一个小岛上, 等待救援", "你每天只能钓鱼度日"}
#define be_1 {{"简介", {"你是这个世界的勇者", "你需要经过你的努力打败恶龙", "过程中你会遇到很多的帮助", "以及很多的陷阱"}, {"开始"}, {""}, {1}},\
{"", {"你从你的床上醒来", "你要干什么"}, {"吃早饭", "出去走走", "再睡一会"}, {"你吃了早饭", "", "你躺在了床上"}, {-1, 2, -2}},\
{"", {"你来到了屋外的路上", "你要干什么"}, {"回家吃早饭", "回家再睡一会", "去铁匠铺"}, {"你回家吃了早饭", "你回家躺在了床上", "你走向了铁匠铺"}, {-1, -2, 3}},\
{"铁匠铺", {"你来到了铁匠铺", "铁匠: 听说你要去迎战恶龙", "铁匠: 你需要准备一把称手的武器", "铁匠: 告诉我你需要什么", "铁匠: 没准我能帮上忙"}, {"离开", "制作武器"}, {"你离开了铁匠铺", ""}, {2, 4}},\
{"铁匠铺", {"铁匠: 你想要什么样的武器"}, {"一把长剑"}, {"你获得了一把长剑"}, {5}},\
{"", {"是时候该出发了"}, {"沿着东边的小路走", "沿着西边的大路走"}, {"", ""}, {6, 14}},\
{"", {"你朝着东边走去", "遇到了一个旅馆"}, {"进入休息", "离开"}, {"你进入了旅馆休息", "你在街头搭帐篷过夜"}, {10, 9}},\
{"", {"你朝着东边走去", "遇到了一个旅馆"}, {"进入休息", "离开"}, {"你进入了旅馆休息", ""}, {8, 12}},\
{"Died", {"你在旅馆被刺杀了"}, {"重生"}, {""}, {1}},\
{"Died", {"你在外留宿后冻死在了路边"}, {"重生"}, {""}, {1}},\
{"", {"你朝着东边走去", "遇到了一个商人"}, {"购买食物", "离开"}, {"你补充了充足的食物", ""}, {7, 11}},\
{"Died", {"你在由于长时间的饥饿死在了路边"}, {"重生"}, {""}, {1}},\
{"", {"你遇到了寺庙"}, {"进入", "离开"}, {"", ""}, {13, 11}},\
{"寺庙", {"你进入了寺庙", "一心学习佛法", "逐渐修炼成佛", "忘记了你的目的"}, {"重生"}, {""}, {1}},\
{"", {"你朝着西边走去", "遇到了一个旅馆"}, {"进入休息", "离开"}, {"你进入了旅馆休息", ""}, {15, 11}},\
{"旅馆", {"你听见楼下有说话的声音"}, {"偷听", "睡觉"}, {"", ""}, {16, 8}},\
{"旅馆", {"你听见旅馆老板想抢你的钱包"}, {"跳窗逃走", "与老板战斗"}, {"", ""}, {17, 18}},\
{"Died", {"你摔死了"}, {"重生"}, {""}, {1}},\
{"旅馆", {"你打赢了老板"}, {"离开"}, {""}, {19}},\
{"", {"门外有两条路"}, {"南边的大路", "北边的小路"}, {"", ""}, {20, 23}},\
{"", {"你朝着南边的大路走去", "遇到了岔路"}, {"南边的大路", "西边的轮船"}, {"", "你走上了轮船"}, {21, 22}},\
{"罗马", {"条条大路通罗马", "你到达了罗马"}, {"重生"}, {""}, {1}},\
{"美洲大陆", {"你开始了你的大航海", "发现了美洲大陆"}, {"重生"}, {""}, {1}},\
{"", {"你朝着北边的小路走去", "发现了山洞"}, {"进入山洞", "直接离开"}, {"你进入了山洞", ""}, {24, 25}},\
{"山洞", {"你在山洞里发现了一个土堆", "然后开始刨土", "于是你发现了世界上第一块山顶洞人的完整头盖骨"}, {"重生"}, {""}, {1}},\
{"", {"你找到了龙的巢穴"}, {"进入", "回家吃饭", "回家睡觉"}, {"你进入了龙的巢穴", "", ""}, {26, -3, -4}},\
{"龙巢", {"你到了龙的巢穴"}, {"与龙战斗", "回家吃饭", "回家睡觉"}, {"你进入了龙的巢穴", "", ""}, {27, -3, -4}},\
{"龙巢", {"你打败了恶龙"}, {"寻找龙蛋"}, {""}, {28}},\
{"龙巢", {"你找到了龙蛋"}, {"破坏龙蛋", "孵化龙蛋", "回家吃饭", "回家睡觉"}, {"", "", "", ""}, {32, 29, -3, -4}},\
{"龙巢", {"你开始孵化龙蛋", "孵化出了小龙"}, {"杀了吃肉", "放生"}, {"", ""}, {30, 31}},\
{"龙巢", {"你被小龙杀死了"}, {"重生"}, {""}, {1}},\
{"龙巢", {"你完成了你的任务"}, {"退出"}, {""}, {-5}},\
{"龙巢", {"你完成了你的任务"}, {"退出"}, {""}, {-5}}}
#define be_2 "获得彩蛋: 条条大路通罗马"
#define be_3 "获得彩蛋: 误入歧途"
#define be_4 "获得彩蛋: 哥伦布大航海"
#define be_5 "获得彩蛋: 意外之喜"
#define be_6 "获得彩蛋: 考古专家"
#define be_7 "获得彩蛋: 学习佛法, 一心向善"
#define be_8 "获得彩蛋: 修炼成仙"
#define be_9 "获得彩蛋: 真香"
#define be_10 "获得彩蛋: 不忘初心"
#define be_11 "获得彩蛋: 牢记使命"
#define be_12 "获得彩蛋: 床真软"
#define be_13 "获得彩蛋: 还是睡觉舒服"
#define be_14 "获得彩蛋: 人是铁, 饭是钢, 一顿不吃饿得慌"
#define be_15 "获得彩蛋: 饿死鬼脱身"
#define be_16 "获得彩蛋: 贤哉, 回也! 一吨食, 一瓢饮, 在陋巷, 人不堪其忧, 回也不改其乐. 贤哉, 回也! "
#define be_17 "获得彩蛋: 睡醒了才能出发"
#define be_18 "获得彩蛋: 床真舒服"
#define be_19 "获得彩蛋: 睡神赋体"
#define be_end "任务完成"
#define sp_1 "1.转盘, 2.退出"
#define sp_2 "转盘消耗: 100累积钓鱼数量+1000金币 当前钓鱼数量: "
#define sp_3 " 当前金币数量: "
#define sp_4 "愚人节彩蛋: 20%"
#define sp_5 "大鱼诱饵: 20%"
#define sp_6 "钻石鱼: 1%"
#define sp_7 "获得成就: 江湖骗子"
#define sp_8 "获得成就: 缺斤少两"
#define sp_9 "获得成就: 老赖"
#define sp_10 "获得愚人节彩蛋*1"
#define sp_11 "获得成就: 鱼人节快乐"
#define sp_12 "大鱼诱饵*1"
#define sp_13 "钻石鱼*1"
#define sp_14 "获得成就: 传说中的鱼"
#define sp_15 "谢谢惠顾"
#endif