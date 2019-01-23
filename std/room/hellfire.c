// Created by stey

#include <ansi.h>
inherit ROOM;
#include "banned.h"


void setup2() 
{ 
    int level= random(10) + 5; 
    int num  = random(5) + 1; 
    set("hellfireroom", 1); 
    // ����ȼ��漰�ֵȼ� 
    if (!query("level")) set("level", level);
    // �ֵĳ�����Ŀ�� 
    if (!query("npc_num")) set("npc_num", num);
    set("alternative_die", 1);  

    setup();
} 

void init()
{ 
    this_object()->init2();
 
    add_action("do_quit", banned_action); 
    add_action("do_cast", "cast"); 
    if (this_object()->query("zuandoors")) 
        add_action("do_zuan", "zuan"); 
    add_action("do_exert", "exert"); 
    add_action("block_cmd", "", 1); 
 
} 
 
int do_zuan() 
{ 
    object me=this_player(); 

    if (me->is_busy() && me->query("no_move")) 
        return notify_fail("����ʱ�����ƶ���\n"); 

    me->move(this_object()->query("zuandoors")); 

    return 1; 
} 
 
int block_cmd() 
{ 
    string verb = query_verb(); 
    object me = this_player();

    // wizard set hellfire allow all.
    if (wizardp(me) && me->query("env/hellfire"))
        return 0;
    // ���߿�allow all
    if (!me->query_temp("hell_died"))
        return 0;

    if (verb=="tell") return 0; 
    if (verb=="chat") return 0; //allow chat 
    if (verb=="help") return 0; 
    if (verb=="look") return 0; 
    if (verb=="quit")
    { 
        this_player()->delete_temp("hell_died"); 
        this_player()->delete("env/invisibility"); 
        this_player()->move("/d/city/kezhan"); 
    } 

    return 1; 
} 
 
int do_quit(string arg)
{ 
    write("�㲻�����������������\n"); 
    if (wizardp(this_player()))
        write("��ʦ�����ͬһ·���ڵ�banned.h�ĵ���\n"); 

    return 1; 
}
 
int do_cast(string arg)
{ 
    if (!arg) return 0; 
    if (arg != "transfer") return 0; 
    command("cast transfer"); 
} 

int do_exert(string arg)
{ 
    if (!arg) return 0; 
    if (arg != "recover" && arg != "heal") return 0; 
    command("cast " + arg); 
} 
void alternative_die(object who) 
{ 
    object killer,corpse; 
    killer = who->query_temp("last_damage_from"); 
 
    if (userp(who))
    { 
        message_vision("$N���ˡ�\n",who); 
        who->set("kee",10);
        who->set("sen",10); 
        if (who->query("eff_kee") < 10)
            who->set("eff_kee",10); 
        if (who->query("eff_sen") < 10)
            who->set("eff_sen",10); 
        who->set("env/invisibility",1); 
        who->set_temp("hell_died",1); 
        if (!killer) killer=who;
        if (objectp(corpse = CHAR_D->make_corpse(who, killer))) 
            corpse->move(this_object()); 
 
        all_inventory(this_object())->remove_killer(who); 
        who->dismiss_team(); 
        who->remove_ride(); 
        who->delete_temp("last_fainted_from"); 
        
    } 
    else
    { 
        if (objectp(corpse = CHAR_D->make_corpse(who, killer))) 
            corpse->move(this_object()); 
        message_vision("$N���ˡ�\n",who); 
        who->reward();
        destruct(who); 
    } 
} 