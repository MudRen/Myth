//Cracked by Roath
// Room: ylt.c
// AceP

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG

��֪�Ӻ�ʱ��ʼ����ɽ����Ů���ϱ�������ôһƬ���֣�����
�б�������ôһλ���ˡ������ڻ�ǰ���³��֣�Ϊ���µ�����
��ף�������顣�˿�������ľ�ȣ�����һ���ʯͷ�ϣ�������
��ط�����һ�����������ر�Ĳ���(book)��
LONG
	);

	set("no_fight", "1");
	set("no_magic", "1");
	set("no_sleep_room", "1");

	set("item_desc", ([
		"book" : "�Ⲿ����ɫ���ر𣬷������š���Ե��������˵�Ǽ������ϵ���\n������Ե�ĵ���������� read book �����ġ�\n"
		]));

	set("exits", ([
		"out" : __DIR__"yltw",
	]));

	set("objects", ([
		__DIR__"npc/yuelao": 1,
	]));

	setup();
}

void init()
{
        add_action("read_book","read");
}

int read_book(string arg)
{
   if (!arg) return 0;
   if (arg!="book") return 0;
   write("\n               ===  ��Ե¼  ===\n\n");
   if(file_size("/log/yl.rc")>0)
     this_player()->start_more( read_file("/log/yl.rc"));
   write("\n");
   return 1;
}
