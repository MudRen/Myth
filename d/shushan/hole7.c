//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIM"������"NOR);                                   
  set ("long", @LONG                                                 
���������������ģ�����������������Ӹ�����(break)��                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
        "south" : __DIR__"hole6",                                      
]));                                                                                                                          
    set("objects",([
        __DIR__"npc/dragon7" : 1,
    ]));    
  setup();                                                           
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object room, ob;
        object me = this_player();

        if (me->query("nyj/shushan")=="done")
                return notify_fail("��ȹ����������������\n");
        if (query("exits/out"))
                return notify_fail("���������Ѿ����ˡ�\n");
        if (objectp(present("dragon", environment(me))))
        return notify_fail("�㻹���Ȱ��������˰ɣ�\n");
        if (!arg || (arg != "hole"))
                return notify_fail("��Ҫ����ʲô��\n");

        if(!( room = find_object(__DIR__"tower")) )
                room = load_object(__DIR__"tower");
        if(objectp(room))
        {
                room->delete("exits");
                room->set("long","�������Ѿ����ˣ�Ҫ�뿪ֻ�ܷɡ�(fly)\n");                                      
                set("exits/out", __DIR__"tower");
                message_vision("$N�þ�ȫ���������������飡\n", this_player());
                write(CYN"��������������ȥ����ң����ڵ������أ���\n");
                write("����ͻȻ������һ������֮�С�\n");
                write("�����������˲������Ｘ��������û�������ܳɹ����룬�ҿ��㻹�ǵ�һ������\n");
                write("����ͻȻ��ʧ��һ������֮�С�\n"NOR);                              
        }

        return 1;
}