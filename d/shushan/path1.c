inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
����ѣ����������죬�߹�ƽ̹�������
�����������ᵽ��·�ļ��ѣ�����һ����
��бб�����ɿ���ľջ�����϶�����
��ͨ��ɽ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"paifang",
  "southdown" : __DIR__"shanjiao",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
