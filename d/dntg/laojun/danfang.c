#include <room.h>
inherit ROOM;

void create()
{
set("short", "����");
set("long", @LONG
    
�������̫���Ͼ����������ڡ�����������һֻһ�˶�ߵ�
��ɫ��¯������������ʲô�������ġ�¯���һ����ܣ�Ȼ��
��ȴ���ܲ���һ˿���ȡ�ǽ�Ƿ���һ¯̴�㣬һ˿��������
�������������ơ�

LONG );


set("exits", ([
  "east"   : "/d/dntg/laojun/hall",
]));
setup();
}
