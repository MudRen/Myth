inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��С������������߻�����֮��ʶ������������ڸ�ˬ������̨��
�������й�һ������С������һ�Ű�ľ��齡�����֮�࣬ɫɫ�ྻ����ɨ
�õ������˺����������л����������У�ʮ�ַ�ï�������ʱ��л���˽�
������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"jiyuan2",
        ]));

        setup();
        replace_program(ROOM);
}

