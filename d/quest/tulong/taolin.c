inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "����");
        set("long", HIG @LONG 
����Ƭï�ܵ�����(peach tree)�����з�����������Ӣ�ͷף�һ
�㵭���ı������������Ĳ��㣬�����ڿ���֮�С�ż����һ����
�������������Գ��ľ����������С·�ѱ��仨���������ѱ治����
������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"lake1",
        ]));

        set("item_desc", ([
            "����": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ��\n",
            "peach tree": "���Ʋ�ϼ����һ����������ֵؿ�����֦ͷ�������̲�ס��ժ(pick)һ֦��֦(taozhi)������\n",
        ]) );

        setup();
}

void init() 
{
   add_action("do_pick", "pick");
}

int do_pick(string arg)
{
   object me, where, zhi;

   me = this_player(); 
        where=environment(me); 
   if(!arg || arg != "taozhi" && arg != "��֦") return 0;       
   if(where->query_temp("marks/taozhi")){
      tell_object(me, "\n��ժ������ͺ��! \n");  
      return 1;
   }    
   zhi = new("/d/quest/tulong/obj/taozhi");
   zhi->move(me);
   where->set_temp("marks/taozhi", 1);
   message_vision("\n$N����ժ��һ֦�һ�������\n", me);
        
   return 1;    
}



