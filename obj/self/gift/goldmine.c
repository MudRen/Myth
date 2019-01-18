// Update by aeddy@2003/04/25

#include <ansi.h>

inherit ITEM;

void create()
{
  	set_name( HIY "ҡǮ��" NOR, ({ "gold mine", "tree"}));
  	set_weight(1000000);
  	if( clonep() ) {
    		set_default_object(__FILE__);
    		set("time", time());
    		// 10 �� 80 gold
		set("money", 100000 + random(700000));
		set("value", 10000);
  	} else {
    		set("unit", "��");
                set("value",100);
		set("long", @LONG

[0;1;40;32m[0;1;40;32m             .     .  .      [0;1;5;40;36m*[0;1;40;32m     .      .          .[0;40;37m              
[0;1;40;32m        .       .      .     #       .           .[0;40;37m                  
[0;1;40;32m           .      .         ###            .      .      .[0;40;37m          
[0;1;40;32m         .      .   "#:. .:[0;1;5;40;33m��[0;1;40;32m"##:. .:[0;1;5;40;34m*[0;1;40;32m"  .      .[0;40;37m                   
[0;1;40;32m             .      . "#[0;1;5;40;31m*[0;1;40;32m##"##[0;1;5;40;31m*[0;1;40;32m"####"  .[0;40;37m                            
[0;1;40;32m          .     "#:.    .:#"###"#:.    .:[0;1;5;40;33m��[0;1;40;32m"  .        .       .[0;40;37m    
[0;1;40;32m     .             "[0;1;5;40;34m*[0;1;40;32m#####[0;1;5;40;35m��[0;1;40;32m#"#####[0;1;5;40;36m*[0;1;40;32m###"        .        .[0;40;37m          
[0;1;40;32m           .    "#:.  "####"###"####"  .:#"   .       .[0;40;37m             
[0;1;40;32m        .     .  "#[0;1;5;40;36m��[0;1;40;32m####""##"[0;1;5;40;33m*[0;1;40;32m#""#######"                  .[0;40;37m       
[0;1;40;32m                   ."[0;1;5;40;33m*[0;1;40;32m#"#[0;1;5;40;31m��[0;1;40;32m##"#####"[0;1;5;40;34m*[0;1;40;32m#"           .      .[0;40;37m          
[0;1;40;32m       .   "[0;1;5;40;36m*[0;1;40;32m:. ...  .:##"#[40;31mҡǮ��[40;32m#"#:.  ... .:[0;1;5;40;36m*[0;1;40;32m"     .[0;40;37m              
[0;1;40;32m         .     "#######"#[40;31m  money  [40;32m#"#######"      .     .[0;40;37m           
[0;1;40;32m       .    .     "#####""#######""#####"    .      .[0;40;37m               
[0;1;40;32m               .     "      000      "    .     .[0;40;37m                   
[0;1;40;32m          .         .   .   000     .        .       .[0;40;37m              
[0;1;40;32m   .. .. ..................O000O........................ ...... ...[0;40;37m 
LONG);
	}

 	setup();
}

void init()
{
	if( !query("dired") ) add_action("do_yao", "yao");
}

int do_yao(string arg)
{
	int valid_time, gold;
	object me = this_player();
	object money;

	if( !arg || ( arg != "tree"  && arg != "gold mine" ) )
		return notify_fail("��Ҫҡʲô��\n");

	if( query("dired") )
		return notify_fail(name(1) + "�Ѿ��ϵ��ˡ�\n");

	if( query("seed_water") != log_id(me) )
		return notify_fail("���ҡǮ���������ֳ����ģ�����ʡʡ�ɡ�\n");

        if( me->is_busy() ) return notify_fail("����æ���ء�\n");
        me->start_busy(2);
	valid_time = time() - query("time");

	if( !wizardp(me) && valid_time < 300 ) {
		message_vision("$N����ҡ����������������飬�����飬�������ӿ쳤�ɣ�\n", me);
		return 1;
	}

	gold = query("money");

	if( gold <= 100 ) {
		message_vision("$Nʹ����ҡ��ҡ$n........\n\nֻ����ž����һ����$n��$Nҡ���ˡ�\n", me, this_object());
		set("dired", 1);
        set("name", "�ϵ���" + HIY + "ҡǮ��" NOR);
		call_out("dest", 20);
		return 1;
	}

	if( query("des_tree") > 20000 ) {
		message_vision(WHT"$Nʹ����ҡ��ҡ$n........\n\n"WHT"ֻ����ž����һ����$n"WHT"��$Nҡ���ˡ�\n"NOR, me, this_object());
		set("dired", 1);
        set("name", "�ϵ���" + HIY + "ҡǮ��" NOR);
		call_out("dest", 20);
		return 1;
	}

	gold = random(gold/2);

	message_vision("$N����ҡ��ҡ$n�����϶�����������һ�����������������\n", me, this_object());
	if( gold >= 100000 ) {
		gold /= 100000;
		money = new("/obj/money/gold");
		message_vision("\n���ϵ�����" + chinese_number(gold) + "��" HIC + money->name() + NOR "��\n", me);
		money->set_amount(gold);
		money->set_temp("seed_money",log_id(me));
		money->move(environment());
		add("money", - ( gold*100000 ));
		return 1;
	}

	if( gold >= 10000 ) {
		gold /= 10000;
		money = new(GOLD_OB);
		message_vision("\n���ϵ�����" + chinese_number(gold) + "��" HIY + money->name() + NOR "��\n", me);
		money->set_amount(gold);
		money->set_temp("seed_money",log_id(me));
		money->move(environment());
		add("money", - ( gold*10000 ));
		return 1;
	}

	if( gold >= 1000 ) {
		gold /= 100;
		money = new(SILVER_OB);
		message_vision("\n���ϵ�����" + chinese_number(gold) + "��" HIW + money->name() + NOR "��\n", me);
		money->set_amount(gold);
		money->set_temp("seed_money",log_id(me));
		money->move(environment());
		add("money", - ( gold*100 ));
		return 1;
	}

	money = new(COIN_OB);
	message_vision("\n���ϵ�����" + chinese_number(gold) + YEL + money->name() + NOR "��\n", me);
	money->set_amount(gold);
	money->set_temp("seed_money",log_id(me));
	money->move(environment());
	add("des_tree", gold);
	add("money", - gold);
	return 1;
}

void dest()
{
	if( !objectp(this_object()) ) return;

	tell_room(environment(), name() + "������ȥ��֦Ҷɢ����һ�ء�\nȻ���ʲô��û����........\n");
	destruct(this_object());
}
