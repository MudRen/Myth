// Room: /u/hkgroup/wow

inherit ROOM;

//#include "honglou.h"

void create()
{
  set ("short", "�շ���");
  set ("long", @LONG
����һ��ʲô��û�еķ��䡣
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
�����������˶������ɺã�ֻ�й��������ˣ�
���������Ž����ںη�����ڣһ�Ѳ�û�ˣ�
�����������˶������ɺã�ֻ�н��������ˣ�
���������ճ�ֻ�޾��޶࣬������ʱ�۱��ˣ�
�����������˶������ɺã�ֻ����������ˣ�
����������������˵���飬����������ȥ�ˣ�
�����������˶������ɺã�ֻ�ж��������ˣ�
�����������ĸ�ĸ�����࣬Т˳����˭���ˣ�

",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yard1",
]));
  set("no_clean_up", 1);
  setup();
}

void init()
{
        object me = this_player();

        message_vision("$N��һ�鿴������ʯͷ(stone)����һ�¡�\n", me);
}


