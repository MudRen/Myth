//Cracked by Roath
// nowords.c
//cglaem...12/16/96.

inherit ITEM;

void init();
void tear();

void create()
{
        set_name("���������顽", ({"book","nowords","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ���������С���ӡ����滮��һЩ���������������ͼ����\n");
        set("material", "paper");
        set("value", 0); // reduced price because now shop's selling
	// price variable.
        set("skill", ([
                        "name": "spells",
                        "dx_required": 50,
                        "sen_cost": 20,
                        "difficulty": 25,
                        "max_skill": 40,
]) );
        }
	setup();
}

void init()
{
        add_action("do_tear", "tear");
}

int do_tear(string arg){
	object ob,me;
	me=this_player();
	if( !this_object()->id(arg) ) return 0;
	ob=new("/d/obj/magic/bishuizhou");
	ob->move(me);
	message_vision("$N˺����������ı�ҳ��������С�������ȡ��һ��СֽƬ��\n", me);
	destruct(this_object());
	return 1;		
}

