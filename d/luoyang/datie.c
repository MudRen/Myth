inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ��������¡�Ĵ����̣����İ���һ����¯��¯��������յ�һ
Ƭͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���
������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־
���ڴ��������������ϰ��֮�˶�ϲ�������������ֵ�������ǽ���п�
����(paizi)��
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sroad5",
        ]));
        set("item_desc",([
                "paizi" : "�޲���������(repair xxx)��\n",
        ]));
        set("objects", ([
                __DIR__"npc/smith" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

