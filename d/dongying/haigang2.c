#include <ansi.h>
inherit ROOM;
void home( object ob ) ;
void create()
{
    set("short", "����");
    set("long", @LONG
������Ƕ�孵��ˡ�������һ���޼ʵĴ󺣣���������ͨ����еĵ�·��
���ϵĿ����ƺ���������,��ʪ�ĺ����д���һ���ȳ�,�ּ�����һ����
�صĻ���,������ʮ�ֹ���.���߲���һ�Ҵ�(chuan)��
LONG
    );
    set("item_desc", ([
        "chuan" : "���Ƕ�孵�������ϵ�Ĵ󴬡���������ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
     "north" :__DIR__"shulin1",
]));
    set("outdoors", 1);
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��������������С�\n", ob);
    ob ->move("/d/dongying/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("home", 20 , ob );
    return 1 ;
}
void home( object ob )
{
     if (!ob) return;
  tell_object(ob , "�����ڵִ������������һ���ۿڡ������´�����\n" ) ;
  ob->move ("/d/dongying/haigang") ;
}
