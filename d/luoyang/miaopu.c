inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
δ��˴������µĻ������������ԡ������г����Ÿ���������������
Ŀ������Ŀ��Ͼ�ӡ������䲻���������֣������������˵Ļ���һ�ش�ʢ
�ŵ�ĵ�������»�����ĵ��Ϊ������ĵ��֮����������ĵ��Ϊ�𣬹ֲ���
���������������ô�����������������οͣ�Ҳ�е��ؾ������Ͳ��ָ�
�͹�����������������Ц����ӭ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"miaoyuan",
                "west" : __DIR__"sroad7",
        ]));
        set("objects", ([
                __DIR__"npc/huanong" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

