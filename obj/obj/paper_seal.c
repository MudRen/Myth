// paper_seal.c

inherit ITEM;

void create()
{
	set_name("�ҷ�ֽ", ({"paper seal", "seal", "paper"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long","���������������ķ�ֽ�����з�淨���Ĺ��á�\n");
	set("unit", "��");
	set("value", 10);
	}
	setup();
}

