
inherit ROOM;

void create()
{
        set("short", "��լ");
        set("long", @LONG
���������ŵ���լ��ס��֪���ļҾ졣ֻ��լ�ڲ��õĸ����ûʣ���
�ⱦ��������ļҾߣ����µİ��裬����ʯ�̳ɵĵ���ӳ���������ԡ���
�������ǲ����������ġ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yamen",
]));

        setup();
        replace_program(ROOM);
}

