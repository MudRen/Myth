//Cracked by Roath
// created by snowcat on 12/16/1997
//modified by opal on 05/99
inherit NPC;

string *names = ({
	"̫�׽���",
	"ʱֵ����",
	"��ֵ����",
	"��ֵ����",
	"��ֵ����",
	"�ݰ�����",
	"��ƿʹ��",
	"��������",
});

int tongtian(object who);
void create()
{
  string str;
	set_name("�Ʒ�Сͯ",({"xiao tong","tong"}));
  set("gender", "����");
  set("age", 13);
	set("attitude", "friendly");
  set("combat_exp", 150000+random(70000));
  set("daoxing", 100000);

  set("per", 10);
  set_skill("parry", 70);
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("blade", 70);
  set_skill("fork", 70);
  set_skill("rake", 70);
  set_skill("hammer", 70);
  set_skill("sword", 70);
  set_skill("stick", 70);
  set_skill("staff", 70);
  set("max_sen",700);
  set("max_gee",700);
  set("max_gin",700);
  set("force",700);
  set("max_force",700);
  set("max_mana",700);
  set("force_factor",10);
	set("inquiry",([
	"ͨ���" : (:tongtian:),
	"���۹�" : (:tongtian:),
	"tongtian": (:tongtian:),
]));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
}
int tongtian(object ob)
{
	object me = this_object();
	object who = this_player();
	string myname = names[random(sizeof(names))] + "�Ļ���";
	string msg = "$N˵������λ"+RANK_D->query_respect(who);
	if ( who->query("combat_exp") < 4000 ||
			who->query("obstacle/tongtian") == "fight"   ) {
	if(me->query("id")!="huashen") me->set_name(myname,({"huashen"}));
	message_vision(msg + 
"��ȡ��·�Ͻ�����ħ��Ҫƾ�汾�°���\n",me);
	message_vision("$N����һ���׹ⲻ���ˣ�\n",me);
	destruct(me);
	return 1;
	}
	if(who->query("obstacle/tongtian") == "won"){
	if (me->query("id")!="huashen") 
	  me->set_name(myname,({"huashen"}));
{
	 message_vision(msg + "������֪���˹��������Ϻ�����������Ľ��𣭣�
	�������˾��������½�Ϊ�񣮣����������н���֮��Ҳ��\n",me);
	 who->set("obstacle/tongtian", "guanyin");
}
	destruct(me);
	return 1;
}
	return 0;
}
void kill_ob(object ob)
{
  object me = this_object();

	string myname = names[random(sizeof(names))] + "�Ļ���";
	if(me->query("id")!="huashen")
	{
	 me->set_name(myname,({"huashen"}));
	 message_vision("$Nһ����Ц,ɲ�Ǽ�Ͳ�������Ӱ��\n",me);
  }
	destruct(me);
}
�
