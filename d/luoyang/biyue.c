inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
ͤ�Ͻ���Ǿޱ��ľ�㡢��÷����ȸ�������������ɡ����ڡ�������֡�
�����ǽ��桢�ٺϡ������ޡ������ޡ����ؽ�����֦ĵ�����࣬����ö�١�
������֮ʱ�������������Զ�����ߣ���ֲ������ݡ�һ��δл��һ����
����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"jiyuan2",
        ]));

        setup();
        replace_program(ROOM);
}

