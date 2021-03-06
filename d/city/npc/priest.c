// Created by waiwai@2001/05/21
// 教父接受洗礼，减少玩家罪孽参数之唯一NPC

inherit NPC;
#include <ansi.h>
string ask_for_xili();

void create()
{
       set_name("教父", ({ "priest", "jiaofu", "jiao", "fu" }) );
       set("gender", "男性" );
       set("age", 74);
       set("long","这个老人金发碧眼，足足有七尺多高。\n");
       set("combat_exp", 30000000);
       set("attitude", "friendly");
	set("chat_chance", 13);
	set("chat_msg", ({
       	"教父道：每个人都无法选择自己的出生的，这是天意！\n",
		"教父道：金钱或许可以买到一切，却买不到真情的！\n",
		"教父道：当你出生的时候，周围的人在笑，而你却在哭！\n",
		"教父道：当你死去的时候，周围的人在哭，而你已解脱！\n",
		"教父道：有钱人并不拥有最多，而是需要最少！\n",
		"教父道：没有真正朋友的人活着等同于死去！\n",
		"教父道：接受洗礼可以减少人的罪孽的，使你活着的时候可以宽恕自己罪恶的心灵！\n",
		"教父道：许多人牺牲自己的健康去换取金钱，然后又牺牲金钱恢复健康！\n",
		"教父道：许多人对未来充满忧虑，却忽视现在。无为今天明天将只有一个失败的昨天！\n",
		"教父道：许多人活着的时候好象永远不会死去，但死去以后又好象从未活过！\n",
		"教父道：人们应该知道：一生中最有价值的不是拥有什么东西，而是拥有什么人！\n",
		"教父道：人们应该知道：不可能取悦所有人。并且应该学会宽恕别人！\n",
		"教父道：要在所爱的人身上造成深度创伤，只要几秒钟；但是治疗创伤则要花上几年--甚至一生！\n",
		"教父道：许多人厌倦童年生活，急于长大，然后又渴望返老还童！\n",
        }));

	set("inquiry", ([
		"洗礼" : (: ask_for_xili :),
		"罪孽" : (: ask_for_xili :),
		"zuinie" : (: ask_for_xili :),
		"xili" : (: ask_for_xili :),
		"kneel" : (: ask_for_xili :),
		]) );

        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_kneel", "kneel");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
       if( ob->query("env/invisibility") ) return;

//	switch( random(1) ) {
//                case 0:
	command("pat " + ob->query("id"));
	command("say 接受洗礼可以减少人的罪孽的！");
//	break;
//	}
}

string ask_for_xili()
{
	object me;

	me = this_player();

	if (!me->query("impurity")) {
		command("smile " + me->query("id"));
		return "这位" + RANK_D->query_respect(me)+"身怀仁爱，主会保佑你平安的！\n";
	} else {


	me->set_temp("pending/zuinie_xili", 1);
	command("pat " + me->query("id"));
	return "这位" + RANK_D->query_respect(me)+
		"如果你诚心洗脱自己的罪孽，请跪 "HIR"(kneel)"NOR CYN" 在主的面前接受洗礼吧。\n"NOR;
	}
}

int do_kneel()
{
	if( !this_player()->query_temp("pending/zuinie_xili") ) return 0;

	if((int)this_player()->query("balance")<200000) { 
		this_player()->delete_temp("pending/zuinie_xili");
		return notify_fail(WHT"你钱庄存款不足"+MONEY_D->money_num(200000)+"不能接受洗礼！\n"NOR);
	}

       if( this_player()->query("env/invisibility") ) {
	message_vision("\n$N对$n说道：你在主的面前也要隐身吗？\n\n" NOR,
		this_player(), this_object() );
	this_player()->delete_temp("pending/zuinie_xili");
	return 1;
	}

	message_vision(HIG"\n$N恭恭敬敬地跪了下来。$n伸出手在$N头顶轻轻地洒了些圣水……\n\n" NOR,
		this_player(), this_object() );

	command("smile");
	this_player()->delete_temp("pending/zuinie_xili");
	this_player()->add("balance", -200000);
	this_player()->add("impurity", -(1+random(100)));

	if ((int)this_player()->query("impurity")<0) 
	this_player()->set("impurity", 0);

	this_player()->save();
	this_player()->start_busy(2);

	return 1;
}
 
