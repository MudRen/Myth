inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
���������רΪ�������������������ġ����ڽ�����ʦ��ʮ��Ϊ�˲�
�ݵģ�����������������ڴ�ѧϰһЩ�����ķ����书��һ�����������
�ȣ�����Ҳ��Ϊ���ѡ��һ����Ľ�����ɡ�
LONG);
        set("exits", ([
                "north" : __DIR__"wroad2",
                "south" : __DIR__"wuguan2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

