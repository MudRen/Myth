inherit ROOM;

void create()
{
        set("short", "�Ƕ���");
        set("long", @LONG
���Ÿ߿��������Ǻ�֮�ϣ����ƷǷ���վ��������������ȥ��һ����
������Ļ��Ǻӽ�������Χ�ڵ��У������Ժ�������ͣ��������ֺܼ�̡�
���ϳ�ˮ������������Ϣ�����µĻ��Ǻ�ˮ�峺���ף�ʱ������Ծ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"dongdoor",
                "eastdown" : __DIR__"guandaoe1",
        ]));

        setup();
        replace_program(ROOM);
}

