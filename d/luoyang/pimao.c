inherit ROOM;

void create()
{
        set("short", "Ƥ����");
        set("long", @LONG
����������һ��Ƥ���꣬ר����ʽ������Ƥ������˵�����Կ�������
��������ʲô������Ƥ�������Ǵ������������ǵظ߼۳���һЩ�黭����
�����ù��ı��⡣�������ù���һ���ǳ�����ϸ�ֳ��ң��������С�ͯ��
���ۡ����֡�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"nroad4",
        ]));
        set("objects", ([
        ]));
        setup();
        replace_program(ROOM);
}

