/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
// Created by waiwai@2000/10/12
// 一个带来(arrive)，去(leave)信息的NPC例子
// 与/d/city/npc/xiaoer.c 的die的msg相对应可以
// 更充分的细致设置各种特色的NPC

inherit NPC;
#include <ansi.h>

void create()
{
    set_name("小猫咪", ({ "catty", "cat", "maomi" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
        set("long", "一只小小的，猫头猫脑的小花猫。\n");
    	 set("combat_exp", 1000000);
        set("per", 25);
        set("zombie", 1);//化为血水的设置
        set("attitude","peaceful");
        set("limbs", ({ "头部", "身体","尾巴" }) );
    	 set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 1000);

	 set("chat_chance", 30);
        set("chat_msg", ({
		(: random_move :)
        }) );

        set("lead_to", 1); // 可跟随标志
        set("arrive_msg", "跳了过来，喵呜～～～");
        set("leave_msg", "＂喵～～＂的一声，跳开了。");
        setup();
}
