inherit ROOM;
#include <room.h> 
#include <ansi.h> 
void create()
{
set("short", HIG"���ƾ�����"NOR);
        set("long", HIW@LONG
�뿪�˴��ƣ��ܶ�Ӣ�ۺ���һʱʧȥ���Լ��ļң�ʧȥ���Լ��ķ���
��ĳ��ĳ�µ�ĳһ�죬���Ƿ�����һ��������Դ������������߿�վ��
�����߿�վ����ʦ��ʮ�����飬�����ǽ������Լ��ľۻ����̳��������
�Ǹ���һ��ʱ�º����е�С�ڰ壬���£�Ӣ���ǿ��Ծ�����㷢�Լ�����
���ˡ�
���������أ������ַ����ˣ��߿�վ����ұ���Щ������ʦ��Ҫ���飬��
������ģͣ�.............
���������أ�һ���µļ�԰���ڴ�ҵ�Ŭ���½����ˣ�����µļ�԰����
....................
LONG NOR
        );
        set("exits", ([ /* sizeof() == 4 */
"south" : "/d/wiz/entrance",
]));
        set("objects", ([
 __DIR__"npc/shizhe" : 1, 
                        ]) );
set("valid_startroom", 1); 
set("no_time",1);  
set("no_fight", 1);  
  call_other("/obj/board/datang_b", "???"); 
set("no_magic", 1);  
               setup();
}

