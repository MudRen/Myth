// Update by waiwai@2003/04/25

#include <localtime.h>
#include <ansi.h>
inherit NPC;

string *msg=({
	"����Ϊ�࣬����ƣ�ͣ���̰����������Ϊ���������ڡ�",
	"и��׹�䣬���о������Ʒ��ն񣬴ݷ���ħ������������",
	"�޳����������������ѧ���ţ������ǻۣ��ɾͱ�ţ��̻�һ�У�Ϥ�Դ��֡�",
	"ƶ���Թ������Ե��������ʩ������Թ�ף�����ɶ񣬲������ˡ�",
	"������ȼ������������������ģ��ռ�һ�С�",
	"Ը���������������࣬�����������Ͼ����֡�",
	"Ը�Դ˹��£�ׯ�Ϸ������ϱ����ض����¼���;�ࡣ",
	"���м����ߣ�Ϥ�������ģ���������������������顣",
	"���ߣ���Ե���ա�",
 	"�����ߣ���Կա�",
	"�������У�売��ڲ���֮�ڡ�",
	"���ĬĬ����ң�ڼ���֮�С�",
	"����ն��ٶ��Σ���������ǧ���",
	"���˼��֪�����뵱ʶ�ġ�",
	"�ľ���������գ��Ĵ����򾳽��塣",
	"������Ƿ�����࣬��ǰ�ɼ���",
	"�����������л����������",
	"�й���������Ϊ�붨֮ԭ��",
	"����ʩ������������֮����",
	"������׾����֪������Ϊ��",
	"�ƼƷǳ����ͷͷ���¡�",
	"��ʹһ�Ĳ�����������ȫ��",
	"���Ʋ�����������Ϊ����������٣�ʵ����ʡ�",
	"ֻҪ����Ե����������ɫ�Կա�",
	"���ش����Ѱ�������Ȼ���������",
});

void create()
{
	set_name("��ɮ", ({"tang monk", "monk", "tang"}) );
	set("title","�Ҳ������˭�����");
	set("gender", "����");
	set("age", 50);
	set("per", 99);
	set("str", 200);
	set("int", 40);
	set("spi", 40);
	set("kar", 40);
	set("cor", 40);
	set("con", 40);
	set("cps", 40);

	set("combat_exp",1000000);
	set("wuxue_exp",10000);
	set("sav_mana",2000);
	set("mana",2000);
	set("max_mana",2000);
	set("class","bonze");
	set_skill("chanting",300);
	
	set("long","��ɮ��ȡ�������Ժ���ڳ����ǿ�ʼ�������ն�������\n");
	set("attitude", "friendly");
        
	setup();
    carry_object("/d/obj/cloth/jia_sha")->wear();
    if(clonep()){
    	call_out("start_chanting", 10);
    }
}

void start_chanting()
{
	set("chanting_times", 50+random(10));

	message_vision(HIY "$Nϯ�ض�����˫Ŀ΢�գ��������������˾��ġ�\n"NOR, this_object());
	call_out("chanting", random(4)+4);
	call_out("start_chanting", 200+random(100));
}

void chanting()
{
	object * obs;
	mixed * local;
	string mark;
	int gain, val;
	
	add("chanting_times", -1);
	if(!query("chanting_times")){
		message_vision(HIY"$N���������۾�������һ����վ��������\n" NOR, this_object());
		return;
	}

	local = localtime(time());
	mark=sprintf("chanting_learn/%d%d%d", local[LT_YEAR], local[LT_MON],
		local[LT_MDAY]);

	obs=all_inventory(environment(this_object()));
	obs=filter_array(obs, (: userp($1) && $1->query("sen")>50 && living($1) :));

	message_vision(sprintf(HIY"$N���������%s\n"NOR, msg[random(sizeof(msg))]), this_object());
	
	foreach(object ob in obs){
		gain=ob->query_skill("chanting", 1)/10;
		gain=1+random(gain)+gain;
		if(gain>10)
			gain=7+random(4);

		val=25+random(10);;
		if(ob->query("bonze/class")=="bonze"){
			val/=2;
			gain*=2;
		}
			
		ob->start_busy(1);
		ob->receive_damage("sen", 20+random(20));
		
		if(ob->query(mark)>500){
			tell_object(ob, "����ôҲ�޷������ɮ�������ݡ�\n");
			continue;
		}
		ob->add(mark, 1);
		if(random(ob->query_int()+ob->query_spi())>val){
			tell_object(ob, "��������ɮ�Ļ����ƺ������˽⡣\n");
			ob->add("potential", gain/2);
			tell_object(ob, sprintf("���Ǳ��������%s�㡣\n", chinese_number(gain/2)));
			gain=gain+random(gain*2);
			ob->improve_skill("chanting", gain);
			tell_object(ob, sprintf("����о���Ϊ������%s�㡣\n", chinese_number(gain)));
		}
	}
	call_out("chanting", random(5)+5);
}