// xiyouxiji.c
// created 4-26-97 pickle

#include "book.h";
inherit ITEM;
inherit BOOK;

int do_read(string arg);
void create()
{
	set_name("���������ǡ�", ({"xiji",}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "



������������������
������������������
��"+HIY+
"�� ��������"+NOR+" ����
������������������
������: ���顡����
��ת¼: ���ա�����
�����: ʮ��������
������������������
\n\n
");
		set("material", "paper");
		set("value", 1000);   
	}
}

void init()
{
    add_action("do_read","read");
}

int do_read(string arg)
{
    if (!this_object()->id(arg))
      return notify_fail("��Ҫ��ʲô��\n");
    read_book(this_player(), this_object()->query("id"));
    return 1;
}
