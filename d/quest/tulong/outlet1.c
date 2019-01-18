inherit ROOM; 
#include <ansi.h> 
void init();
int do_move(string arg);
int do_enter(object me);

void create()
{ 
      set("short", "��ɰ̨");
      set("long", HIG @LONG 
��ɰ̨Լ��һ�ɼ�����������ϸɳ�̾ͣ�����̨��ǳ���ƽ����  
̨������һ���ʯͷ(stone)����ס��Ȫ�ۡ�
LONG);
      set("exits",([
          "east" : __DIR__"spirit4",
      ]));
      set("item_desc", ([
          "stone" : "���ʯͷ����������̫����Ӧ�ÿ��԰ᶯ(move)����\n",
      ]));
//    set("no_clean_up", 0);
      setup();
}

void init()
{
        add_action("do_move", "move");
        add_action("do_enter", "enter");
}

int do_move(string arg)
{      
        object room; 
        object me=this_player();
        if(!arg || arg!="stone")
            return notify_fail("��Ҫ�ƶ�ʲô��\n");
        if((int)me->query_str()>25)
        {
                message_vision(HIC"$N�����ƿ���ʯͷ��Ȫˮ�ֿ�ʼ���˳������ƺ�����Ǳ��ȥ(enter)��\n"NOR,this_player() ); 
                message_vision(HIC"һֻС���������$N��ǰ��˵��лл��⿪�ڶ�����ӡ���������ǰ���ɡ�\n"NOR,this_player() ); 
                this_player()->set_temp("m_success/����",1);
                set("move_stone",1);
                if(!( room = find_object(__DIR__"entrance")) )
                        room = load_object(__DIR__"entrance");
                if(objectp(room)) 
                {                
                        room->set("exits/down", __DIR__"spirit3");
                        message("vision","Ȫ������ӿ����Ȫˮ��\n",room);
                }                
        }
        else
                message_vision("$Nʹ�����̵�����ҲŲ����ʯͷ��ֻ���㬵ط����ˡ�\n", this_player());    
        return 1;       
}

int do_enter(object me)
{
        object room;
        object where;
        me=this_player();
        where=environment(me); 
        if(!where->query("move_stone"))
                return notify_fail("��Ҫ����ȥ��\n");        
        if(!( room = find_object(__DIR__"spirit5")) )
                room = load_object(__DIR__"spirit5");
        message_vision("$N�����ˡ�һ��������Ȫˮ�С�\n",me); 
        set("move_stone",0);        
        me->move(room);
        return 1;
}


