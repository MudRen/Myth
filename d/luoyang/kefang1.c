
inherit ROOM;

void create()
{
        set("short", "���ͷ�");
        set("long", @LONG
����һ��ܴ�Ŀͷ���������Ȼ�򵥣���ʮ�ָɾ����ࡣ��ǽ����ʮ
����Сľ�������ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ�������ʱ�Ļ�
�п��˽���˯������˯�õ��˺��Ծ������������߳��ͷ���
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"kezhan2",
        ]));

        setup();
        replace_program(ROOM);
}

