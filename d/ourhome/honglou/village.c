// Room: /u/hkgroup/village
inherit ROOM;

//#include "honglou.h"

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������������п�����������ɽׯ����������ˮ��ɣ����������
��������һ�贺���죬ʮ�ﵾ���㡣ʢ���ޡ��٣������֯æ��

����һ���ƻ�(sign)������������ҡ�

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "
��������������������

",
]));
  set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"april",
  "south" : __DIR__"yard1",
  "north" : __DIR__"cave",
  "east" : __DIR__"fisher",
  "enter" : __DIR__"cottage",
]));
//  set("outdoors", "/u/hkgroup");

  setup();
}

/*
int valid_leave(object me, string dir)
{
	string membership = memberhood(me);

        if ( dir=="enter" &&
//		( membership == "(NotMember)" || membership == "(guest)") ) 
              ( membership == "(NotMember)"))
        {
        return notify_fail("ֻ�����ء���һ����������Ŷ���������������ײ������~~~~~~~~\n");
        }
        return ::valid_leave(me, dir);
}
*/
