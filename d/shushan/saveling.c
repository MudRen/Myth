//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;                                                        
#include <ansi.h>                                                                     
void create ()                                                       
{                                                                    
  set ("short", "������");                                   
  set ("long", @LONG                                                 
һ���������������������ǰ���������������Ͽ����㾪�ȵط��֣�
�����и�Щʲô��������һŮ�����������ھ����ϡ�                                           
LONG);                                                          
set("item_desc", ([
                "girl": @TEXT
�㿴��������Ǵ�����İ���Ů���㿴�����Ŀ��������Ƿ�ῼ�Ǿȣ�
TEXT        ]) );                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
  "south" : __DIR__"pole",                                      
]));                                                                                                                          
        set("no_fight",1);
        set("no_magic",1);
  setup();                                                           
}

void init()
{
        add_action("do_jiu", "jiu");
}

int do_jiu(string arg)
{
        object room, ob;
        object me = this_player();

        if (query("exits/down"))
                return notify_fail("�����Ѿ������ˡ�\n");

        if (!arg || (arg != "girl"))
                return notify_fail("��Ҫ��˭��\n");

        if(!( room = find_object(__DIR__"hole1")) )
                room = load_object(__DIR__"hole1");
        if(objectp(room))
        {
                set("exits/down", __DIR__"hole1");
                message_vision("$N��Ů������������\n", this_player());
                write(CYN"Ů��������лл������ң��ҽ������������ֻ�Ǿ������������������ǻ��ǳ���ȥ����\n");
                write("����ͻȻ������һ������֮�С�\n");
                write("�������������������Ｘ��������û�������ܳɹ����룬�ҿ����ǻ���ʡ�����ѡ���\n");
                write("��֪���ﴫ�������ɵ����������ǵ�δ�أ�ֻҪ�����ܴ�������������������������������°ɣ���\n");
                write("���������̫���ˣ������л��������ң����������������¾Ͱ����ˣ������Ӧ(daying)�ң���\n");
                write("�����������һ�ȥ֪ͨ��ң�׼���뿪����\n");
                write("����ͻȻ��ʧ��һ������֮�С�\n"NOR);
                ob = new("/d/shushan/npc/linger");              
                ob->move("/d/shushan/saveling");
                me->set_temp("shushan/linger_saver_1",1);
                room->set("exits/up", __FILE__);
                
        }

        return 1;
}