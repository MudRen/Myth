#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ͼ��");
  set ("long", @LONG

������ʿ��ϲ���ľ����ռ����صĵ�ͼ��
���Ժܶ�������ʿ��ļ�迪�������ͼ��
�����кܶ�����ĵ�ͼ,���Һ��ǳ���.
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
       "south" : "/d/calvin/milin/milin4",    
]));

  setup();
}
