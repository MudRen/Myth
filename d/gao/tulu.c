// shanlu.c

inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

һ��ʪ������С·��·�߿������Ұ����·��С����Ϫˮ������
���ţ�ˮ����Ҳż���������ܣ����ɣ��Ľ�����ԶԶ��ȥ������
�������͵ģ����߿������߼����ϱ߾͵��˴��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"daotian2",
"south" : __DIR__"cunkou",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


