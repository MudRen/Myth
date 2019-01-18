// Created by stey

#include <ansi.h>
inherit ROOM;
#include <banned.h>



void setup2()
{
   
    int level;
    set("mofengroom", 1);
  
    if(this_object()->qurey("level")) level=this_object()->qurey("level");
      else level=random(40)+10;
    
    if(this_object()->qurey("npc_number")> 1){ 
         for(i=0;this_object()->query("npc_number");i++)
          {  
    
               guai=new("/d/mofeng/npc/stey/guai"); 
               guai->create(level,level); 
               guai->move(this_object()); 
           } 
                                             } 
    
    set("alternative_die", 1);

    setup();
}

void init()
{
    this_object()->init2();

    add_action("do_quit", banned_action);




}

int do_quit(string arg)
{
    write("�㲻�����������������\n");
    if (wizardp(this_player()))
        write("��ʦ�����ͬһ·���ڵ�banned.h�ĵ���\n");

    return 1;
}

void alternative_die(object who)
{
    object killer,corpse;
    killer = who->query_temp("last_damage_from");

    if (userp(who))
    {
        message_vision("$N���ˡ�\n",who);
        who->set("kee",100);
        who->set("sen",100);
        if (who->query("eff_kee") < 10)
            who->set("eff_kee",100);
        if (who->query("eff_sen") < 10)
            who->set("eff_sen",100);

        who->dismiss_team();
        who->remove_ride();
        who->delete_temp("last_fainted_from");
        who->move("/d/quest/mofeng/enter");
        who->unconcious();
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
