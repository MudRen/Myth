//����������
//��������

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

��԰�зǳ������ţ�������ʲô�ˡ���˵�ǻ�԰����ֵ��ǲ�
���л��䡣��ֲ�Ĵ����Щ��ֵĲ��࣬������ɫ�ġ���һ�ѣ�
��һ�أ����ǹ滮�ķǳ���ϸ��������԰����һ��С�����ڲ�ľ
����֮���Ե÷ǳ����¡�
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
//  set("outdoors", 1);
  
  set("position", "��");
  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hua_ken",
  "southeast" : __DIR__"hua_zhen",
]));
//      
        set("water", 1);
//  
  setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{       
        object me;
        me=this_player();

        message_vision("$N����һ������Ȼ������Сͤ�С�\n",me);
                me->move("/d/qujing/bibotan/furong");
                me->set_temp("enter_position", "��");
                tell_room( environment(me), "����һ�����и������˽�����\n", ({me}));
                return 1;
}

