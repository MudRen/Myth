//by dewbaby
//shishi2 
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
{ 
         set ("short", YEL"����ʯ��"NOR); 
         set ("long", @LONG 
        
����һ�䲼���ҳ���Сʯ�ң�����ȥ�Ѿ��ܾ�û����������
�����㳯��ʯ������һ��ȥ�������˼���ģ������Ľ�ӡ
(footprint)��
LONG); 
        
         
        set("exits", ([ /* sizeof() == 1 */ 
                     "west" : __DIR__"hudi3",       
        ])); 
        set("item_desc", ([
            "footprint" : "����ģ������Ľ�ӡ���ƺ����Բ��ɾ�(clean)��\n",
            "spell" : "һ��С��ֵ�СֽƬ����֪������д��ʲô�����Կ�(look)һ�¡�\n",
        ]));
        set("no_clean_up",0);
        setup(); 
}

void init() 
{ 
            add_action("do_look","look"); 
            add_action("do_clean","clean"); 
} 

int do_clean(string arg)
{  
        object me;
        me=this_player();
        if(!arg || arg!="footprint") return 0;
        message_vision(HIY"$N����������������˲����ϵĽ�ӡ��\n\n"HIW"ͻȻ�㷢�����澹Ȼ��һ������!\n"NOR,me);
        me->move(__DIR__"mishi1");
        tell_object(me,WHT"�·������е�ʲô�����������㲻�����������˽�ȥ!\n"NOR);
        return 1;
}


int do_look(string arg)
{      object me; 
       me=this_player();
       if(!arg || arg!="spell") return 0;
       message_vision(HIM"$N���˹�ȥ����������һ��д�������СֽƬ��\n",me,NOR);
       if (me->query("gender")!="Ů��")
       {
          message_vision(HIR"ͻȻ�㷢���Լ���һ���Ϻ�������ס...\n\n�㽥��ʧȥ������...\n\n�������Խ��Խģ��...\n",me);
          me->delete_temp("last_damage_from");
          me->delete_temp("last_opponent");
          me->set_temp("death_msg","��һ�����ص��ϻ������ˡ�\n");
          me->die();
       }
       else {
          me->move("/u/dewbaby/wangxian/hudi3");
            }
/*
}
   else {
     this_player()->start_busy(3);
     this_player()->set(sen, (int)me->query(max_sen));
     this_player()->set(eff_sen, (int)me->query(max_sen));
     this_player()->set(gin, (int)me->query(max_gin));
     this_player()->set(eff_gin, (int)me->query(max_gin));
     this_player()->set(eff_kee, (int)me->query(max_kee));
     message_vision(HIR"ͻȻ�㷢���Լ���һ���Ϻ�������ס...\n\n�㽥��ʧȥ������...\n\n�������Խ��Խģ��...\n",me,NOR);
     me->delete_temp("last_damage_from");
     me->delete_temp("last_opponent");
     me->set_temp("death_msg","��һ�����ص��ϻ������ˡ�);
             me->die();
}
*/
     return 1;
}
        
 

