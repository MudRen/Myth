// 天绝帮信物
#include <ansi.h>
#include <weapon.h>
#define CLUB_NAME "欢乐城"
#define CLUB_ID "hapyy"
#define CLUB_CHANNEL "hapyy"
#define CLUB_MARK "hapyy necklace"
inherit SWORD;
private string *members_level = ({
	"荣誉帮众", //0
	"行动组", //1
	"帮众", //2
	"护法", //3
	"副堂主", //4
	"堂主", //5
	"长老", //6
	"金牌杀手", //7
	"副帮主", //8
	"压寨夫人", //9
	"帮主", //10
});
void create()
{
        set_name(HIR"天绝令"NOR,({"tianjue necklace","necklace","club_mark","sword","jian"}));
	set_weight(0);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("material","gold");
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","快");
	set("long",@LONG

		天绝令出	莫敢不从
	
		遇神杀神	遇佛轼佛

这是一块火红色的令牌，上面大大的一个“绝”字。凡见此令牌者，
如帮主亲临，所有帮众必须听令。
你可以用(help tianjue)来查看有什么天绝帮指令。若想了解天绝帮
的历史可以用(about tianjue)来取得进一步的资料。

LONG
);
	}
	set("club_id",CLUB_ID);
	set("club",CLUB_NAME);
	set("sub_club",({"绝浪堂","绝霜堂","绝剑堂","绝影堂","绝心堂","绝风堂","绝情堂","绝杀堂"}));
	set("club_max_level",10);
        init_sword(2);
	setup();
	set("volume",1);
}

//int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
 	if(wizardp(this_player()))
 	{
 		 info = ([
		 "level": wiz_level(this_player()),
		 "title": "天绝帮荣誉帮众",
		 "info1": "无",
		 "info2": ctime(time()),
		 "info3": ""
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
	}
	else 
	{
 		tell_object(this_player(),this_object()->name()+"突然从你身上飞出，渐渐消失在远方。\n");
 		this_player()->delete("club");
 		destruct(this_object());
 		return;
 	}
 }
 switch(level)
 {
  case 10:
		add_action("do_handover","handover");
  case 8:
		add_action("no_suicide","suicide"); //防止自杀
  case 7:
		add_action("do_givepower","givepower");
		add_action("do_listmember","listmember");
  case 6:
  		add_action("do_accept","jieshou");
		add_action("do_kickout","kickout");
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 5:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_about","about");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
}

int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "【荣誉会员】天绝帮荣誉帮众  ";
 level=user->query("combat_exp")/100000;
 if(level>100) 	str = "【????????】";
 else if(level<11)	str = "【第 "+chinese_number(level)+" 级】";
 else if(level<21) 	str = "【第"+chinese_number(level)+"级】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"级】";
 else str = "【"+chinese_number(level)+"级】";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
 	case 10: str+="天绝帮龙头老大  "; break;
 	case 9: str+="天绝帮压寨夫人  "; break;
 	case 8: str+="天绝帮副帮主    "; break;
 	case 7: str+="天绝帮金牌杀手  "; break;
 	case 6: str+="天绝帮资深长老  "; break;
 	case 5: str+=info["info1"]+"分堂主    "; break;
 	case 4: str+=info["info1"]+"副堂主    "; break;
 	case 3: str+="天绝帮护法      "; break;
 	case 2: str+="天绝帮一般帮众  "; break;
 	
 	default: 
 		if(info["info1"]!="无")
 		{
 		       str+=info["info1"]+"堂员      "; break;
 		} else str+="天绝帮行动组员  ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
	lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
	if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
	else return (lv1 - lv2);
}

int do_members(string arg)
{
	object *users,me;
	string str,*list;
	int i,ppl_cnt,idle;
	me=this_player();
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "◎ "+CLUB_NAME+": \n";
	str += "─────────────────────────────────────\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(!me->visible(users[i]) && wizardp(users[i]) ) continue;
			str = sprintf("%s%12s%-16s %s(%s)",
				str,
				show_level(users[i]),
				RANK_D->query_level(users[i]),
				users[i]->name(1),
				users[i]->query("id"),
			);
			if(users[i]->query_temp("killer")) str+=HIR" [杀人犯]"NOR;
			idle=query_idle(users[i]);
			if(users[i]->query_temp("invis")) str+=HIB"(隐形)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<断线中>"NOR;
			if(idle>60) str +=sprintf(HIY" (发呆%d分钟)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s目前共有 %d 位成员在线上.\n", str, ppl_cnt);
	this_player()->start_more(str);
	return 1;
}

int do_include(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("include <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
			if(me_info["level"] != 5 ) return notify_fail("只有分堂主能将帮众收入分堂。\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("只有分堂主能将帮众收入分堂。\n");
			if(ob_info["level"] != 2 || ob_info["info1"]!="无")
				return notify_fail("只有一般帮众可以收入你的分堂。\n");
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N将$n收入"+sub+", 并拍拍$n的肩膀说: 今后就看你的表现了。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));		
		if(sizeof(ob_info))
		{
			if(!sub=me_info["info1"] || me_info["level"]!=5 ) return notify_fail("只有分堂主能免除堂员职务\n");
			if(ob_info["level"] != 1 ) return notify_fail("你不够资格解除对方的职务。\n");
			if(ob_info["info1"] != sub) return notify_fail("对方并不属于你的分堂。\n");
			ob_info["info1"]="无";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N解除了$n在"+sub+"的职务, 摇摇头说: 又少了一个人才...真是可惜啊。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}
//收人
int do_accept(string arg)
{
	string *clubs;
	object ob,mark,me;
	mapping info;
	me=this_player();
        if(!arg) return notify_fail("你要让谁加入"+CLUB_NAME+"？\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("这里有这个人吗？\n");
	        if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
		if(ob->query_temp("joinclub") != me->query("id") )
		{
			return notify_fail("对方并没有向你申请入会(joinclub).\n");
		}
		clubs=CLUB_D->find_player_club(getuid(ob));
		if(sizeof(clubs)>0)
		{
			if(clubs[0]==CLUB_ID) return notify_fail("对方已经是"+CLUB_NAME+"的一份子了。\n");
			else return notify_fail("对方已经加入了别的帮派。\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("帮会信物取得失败。\n");
		 message_vision("$N给了$n一"+mark->query("unit")+mark->query("name")+", 并隆重的迎接$n成为"+CLUB_NAME+"的一份子。\n",me,ob);
		 info = ([
		 "level": 1,
		 "title": "天绝帮行动组员",
		 "info1": "无",
		 "info2": ctime(time()),
		 "info3": me->name_id(1),
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"tianjue"}));
		 ob->add("club", "天绝帮");
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string *tuned_ch;
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("你要将谁踢出"+CLUB_NAME+"？\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("这里有这个人吗？\n");
	        if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
				
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"])
				return notify_fail("你不够资格将对方踢出"+CLUB_NAME+"。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
				return notify_fail("你不够资格将对方踢出"+CLUB_NAME+"。\n");
			tuned_ch = ob->query("channels");
			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
			{
				tuned_ch -= ({ CLUB_CHANNEL });
				ob->set("channels", tuned_ch);
			}
			ob->delete("club");
			if(!mark=present(CLUB_MARK,ob))
			{
				write("帮会信物取得失败。\n");
			}
			else
			{
 				message_vision("$N没收了$n的"+mark->query("name")+", 并强制$n退出"+CLUB_NAME+"。\n",me,ob);
 				destruct(mark);
 			}
 			CLUB_D->remove_member(CLUB_ID,getuid(ob));
 			ob->save();
 			return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <人名> to <分堂名>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <分堂名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 2)
				return notify_fail("只有一般帮众可以成为分堂主。\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("目前可用的分堂为 <绝浪堂> <绝霜堂> <绝剑堂> <绝影堂> <绝心堂> <绝风堂> <绝情堂> <绝杀堂>\n");
			ob_info["level"]=5;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("天绝帮信物取得失败。\n");
			}
			else
			{
	 			message_vision("$N将$n提升为"+sub+"分堂主, 并和$n握手勉励一番。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("retire <人名> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me) return notify_fail("这里有这个人吗？\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 5) return notify_fail("对象并不是分堂主。\n");
			sub=ob_info["info1"];

			ob_info["level"]=1;
			ob_info["info1"]="无";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

			if(!mark=present(CLUB_MARK,ob))
			{
				write("帮会信物取得失败。\n");
			}
			else
			{
	 			message_vision("$N免除了$n的"+sub+"分堂主职务。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,type,res;
	int level;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <人名> to <等级>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <人名> to <等级>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me) return notify_fail("这里有这个人吗？\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"]) return notify_fail("你没有资格改变对方的职务等级。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
					return notify_fail("你没有资格改变对方的职务等级。\n");
			if(level >= me_info["level"])
				return notify_fail("你没有资格提升对方的职务等级到这个等级。\n");
			if(level == ob_info["level"])
				return notify_fail("对方已经是"+(string)members_level[level]+"了。\n");
			if(level > 9 || level < 1 )
				return notify_fail("目前等级分为 <1:行动组员> <2:帮众> <3:护法> <4:副堂主> <5:堂主> <6:长老> <7:金牌杀手> <8:副帮主> <9:压寨夫人> <10:帮主> \n");
			if( level > ob_info["level"] )
			{
				type="提升";
				res ="并和$n握手勉励一番";
			}
			else
			{
				type = "降";
				res ="并拍拍$n的肩膀期勉$n能将功\折罪";
			}
			switch(level)
			{
				case 1:
					ob_info["level"]=1;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 2:
					ob_info["level"]=2;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 3:
					ob_info["level"]=3;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 4:
					ob_info["level"]=4;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 5:
					return notify_fail("请用subleader指令来指定一个分旗。\n");
					break;
				case 6:
					ob_info["level"]=6;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 7:
					ob_info["level"]=7;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 8:
					ob_info["level"]=8;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 9:
					ob_info["level"]=9;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 10:
					return notify_fail("请用handover指令做指挥权移交。\n");
					break;
				default: return notify_fail("参数错误。\n");
				
			}
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("天绝帮信物取得失败。\n");
			}
			else
			{
				message_vision("$N将$n的职位等级"+type+"为"+(string)members_level[level]+"(等级"+(string)level+"), "+res+"。\n",me,ob);
				mark->move(ob);
			}
			ob->save();
			return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_handover(string arg)
{
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
        if(!arg) return notify_fail("你要将大权移交给谁？\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me) return notify_fail("这里有这个人吗？\n");
		
		if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("你不是真正的帮会领导人。\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
		 	CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
		 	
		 	ob_info["level"]=10;
		 	ob_info["info1"]="无";
		 	ob_info["info2"]=ctime(time());
		 	ob_info["info3"]=me->name_id(1);
		 	CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			
			me_info["level"]=7;
		 	me_info["info1"]="无";
		 	me_info["info2"]=ctime(time());
		 	me_info["info3"]=me->name_id(1);
			CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
		 	
		 	mark=present(CLUB_MARK, me);
		 	if(!mark)
		 	{
		 		write("天绝帮信物取得失败。\n");
			}
			else
			{
				mark->move(me);
			}
			mark=present(CLUB_MARK, ob);
		 	if(!mark)
		 	{
		 		write("天绝帮信物取得失败。\n");
			}
			else
			{
				mark->move(ob);
			}
			message_vision("$N将"+CLUB_NAME+"的总指挥权移交给$n。\n",me,ob);
			message( "channel:tianjue",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")将"+CLUB_NAME+"指挥权移交给"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
			ob->save();
			me->save();
			return 1;
		}
		 else return notify_fail("对方并不是"+CLUB_NAME+"的一份子。\n");
	}
	return 1;
}

int do_leaveclub(string arg)
{
	string *tuned_ch;
	object mark,me;
	me=this_player();
	
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
		return notify_fail("你必须先将大权转移才能离开"+CLUB_NAME+"。\n");
	CLUB_D->remove_member(CLUB_ID,getuid(me));
	message_vision("$N主动退出了"+CLUB_NAME+"。\n",me);
	message( "channel:tianjue",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主动退出了"+CLUB_NAME+"。\n"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	if(!mark=present(CLUB_MARK,me))
	{
		write("天绝帮信物取得失败。\n");
	} else destruct(mark);
	me->save();
	return 1;
}

int no_suicide(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
	{
		write("身为"+CLUB_NAME+"高级长官, 交出指挥权之前不可轻生, 以免后继无人。\n");
		return 1;
	}
	return 0;
}

int do_listmember(string arg)
{
	string *list,*members,temp,output;
	int i,j;
	mapping club;
	list=CLUB_D->club_members(CLUB_ID);
	club=CLUB_D->query_club_record(CLUB_ID);
	members=keys(club);
	output="\n目前"+CLUB_NAME+"登记有案的成员有:\n";
	if(arg=="long")
	{
		for(i=this_object()->query("club_max_level");i>0;i--)
		{
			for(j=0;j<sizeof(members);j++)
			{
				if(club[members[j]]["level"]==i) output=sprintf("%s %12s 帮会等级: %d\n",output,members[j],i);
			}
		}
		output=sprintf("%s \n目前%s共计有: %d 名成员。\n",output,CLUB_NAME,sizeof(members));
		write(output);
		return 1;
	}
	temp=CLUB_D->query_club_leader(CLUB_ID);
	output=sprintf("%s 领导人: %12s\n",output,temp);
	list-=({temp});
	output=sprintf("%s 其他:\n",output,temp);
	output+=CLUB_D->show_club_members(CLUB_ID);
	output=sprintf("%s目前%s共计有: %d 名成员。\n",output,CLUB_NAME,sizeof(members));
	write(output);
	return 1;
}


int do_help(string arg)
{
 if(arg=="tianjue")
 {
  write(@HELP

       　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
                              天绝帮信物的辅助说明                        
       ┌───────────────┬─────────┬──────┐
       │  指令格式                    │说明              │权限        │
       ├───────────────┼─────────┼──────┤
       │  help plate                  │本辅助讯息        │帮众        │
       │  club <你的讯息>             │帮会专用频道      │帮众        │
       │  members                     │列出线上帮会成员  │帮众        │
       │  leaveclub                   │主动退出帮会      │帮众        │
       │  include <人名>              │将某人收入分堂    │堂主专用    │
       │  dismiss <人名>              │取消某人分堂职务  │堂主专用    │
       │  accept <人名>               │让某人加入帮会    │长老以上    │
       │  kickout <人名>              │将某人逐出帮会    │长老以上    │
       │  subleader <人名> to <分堂名>│升级某人为分堂主  │长老以上    │
       │  retire <人名>               │撤除某人分堂主职位│长老以上    │
       │  givepower <人名> to <等级>  │改变某人的职位    │杀手以上    │
       │  handover <人名>             │掌门职务交接      │帮主        │
       │  listmember                  │帮会名册          │杀手以上    │
       └───────────────┴─────────┴──────┘
	 ◎ 使用 accept 指令必须对方先用 joinclub 指令申请才能生效。
         ◎ 天绝帮目前有五个分堂: 【绝浪堂】、【绝霜堂】、【绝剑堂】、【绝影堂】
         			　【绝心堂】、【绝风堂】、【绝情堂】、【绝杀堂】。
         ◎ 等级分为: <1:行动组员> <2:帮众> <3:护法> <4:副堂主> <5:堂主> <6:长老>
         	　　　<7:金牌杀手> <8:副帮主> <9:压寨夫人> <10:帮主>。

HELP
  );
  return 1;
 }
 return 0;
}
int do_about(string arg)
{
   if(arg=="happy")
 {
  write(@ABOUT

●天绝帮信物——天绝令

传说几百年前，曾有七个人，以其各有的独门武功称霸江湖，这七个
高手就是曾叱吒江湖的“天绝帮”天绝七煞。
他们的帮派信物——天绝令，天绝令一出，莫敢不从，江湖上许多人
见到该令均纷纷离避，以免受到不必要的牵连。不过，这个风云大帮
，不知道什么原因，销声匿迹，江湖上也得到一时的宁静。
现在天绝令重出江湖，一番江湖波折也将番起。

ABOUT
  );
  return 1;
 }
 return 0;
}
