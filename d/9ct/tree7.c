// ������ ������ by Calvin

#include <ansi.h>
inherit __DIR__"tree";

void falldown(object,object);
void create()
{
        set("short", HIC"���ء�������"NOR);
  set ("long", @LONG

          ��������������������������������������
          ��������������������������������������
          ��������˾�ǧɽ��  ˮ���˶ʯ��������
          ��������������������������������������
          ��������������������������������������

LONG);

        set("exits", ([
  "down": __DIR__"qi",
        ]));

        set("objects", ([
               "/d/9ct/obj/bing.c" : 1,
              ]));
        set("9ctroom",1);
        set("alternative_die",1);

        setup();
}

void init() 
{
        object me=this_player();    
        add_action("do_cast","cast");        
        if (me->query("env/invisibility"))  
            me->delete("env/invisibility");
}  

int do_cast(string arg) { 
        if(!arg) return 0;
        if(arg !="transfer" ) write("�㲻�����������������\n");    
        command("cast transfer");
        return 1;
}


void alternative_die(object who)  
{  
        object killer,corpse;
        
        killer = who->query_temp("last_damage_from");  

        if (userp(who)) {  
                message_vision("$N���ˡ�\n",who);  
                who->set("kee",10); who->set("sen",10);  
                if(who->query("eff_kee")<10) who->set("eff_kee",10);  
                if(who->query("eff_sen")<10) who->set("eff_sen",10);           
                if(!killer) killer=who; 
//        if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
//                corpse->move(this_object());  
                all_inventory(this_object())->remove_killer(who);               
                who->remove_ride();  
                who->dismiss_team();  
                who->delete_temp("last_fainted_from");  
                who->move("/d/city/kezhan");  
        }  
        else {  
                if( objectp(corpse = CHAR_D->make_corpse(who, killer)) )  
                        corpse->move(this_object());  
                message_vision("$N���ˡ�\n",who);  
                who->reward();       
                destruct(who);                  
        }  
}
