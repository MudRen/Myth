inherit ROOM;

void create()
{
        set("short", "��ݺ�Ժ");
        set("long", @LONG
��������ݵĺ�Ժ��������ݵĹ���������������������һЩ������
Ϊ�ĵ��Ӵ����书���õ�����ָ����������ǳ��һ�����������Ĵ�Ժ�ӣ�
�����Ƚ��ľ���������������ô���������֣���һ����������ĺõط���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"wuguan",
        ]));

        setup();
        replace_program(ROOM);
}

