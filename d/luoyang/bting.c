

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������ŵı���������֪�����鷿��������һ�������ĺ�ľ������
�鰸�����ҵط��ż������ƵĹż���ǽ�Ϲ��ż����ֻ���ȫ������������
�ʣ�һ��С��ͯ�����������鷿�е��鼮��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"yamen",
        ]));

        setup();
        replace_program(ROOM);
}

