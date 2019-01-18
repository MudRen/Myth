inherit NPC;

int start_change(string arg);

void create()
{
       set_name("��ɽ����", ({"shi zhe"}));
       setup();
}

void init()
{
	::init();
  add_action("start_change", "change");
  
}

int start_change(string arg)
{
			int sword,force,spells,dodge;
			object who=this_player();
           if (who->query_temp("shushan/changed")=="done")
            return notify_fail("���Ѿ�ת����ϣ�����ɽ�����ˡ�\n");
		    
			
if ((who->query("family/family_name")!="��ɽ") && (who->query("family/family_name")!="��ɽ����"))
			return notify_fail("�����ɽ���£��޷�ת����\n");
			


			sword=(int)who->query_skill("songhe-sword", 1);
			force=(int)who->query_skill("shushan-force", 1);
			spells=(int)who->query_skill("xianfeng-spells", 1);
			dodge=(int)who->query_skill("zuixian-steps", 1);

                        who->delete_skill("songhe-sword");
                        who->delete_skill("shushan-force");
                        who->delete_skill("xianfeng-spells");
                        who->delete_skill("zuixian-steps");
			who->set_skill("shushan-jianfa",sword);
			who->set_skill("taoism",spells);
			who->set_skill("zixia-shengong",force);
			who->set_skill("sevensteps",dodge);
			who->map_skill("force", "zixia-shengong");
			who->map_skill("spells","taoism");
			who->set("family/family_name","��ɽ����");
			command("smile");
			command("pat"+who->query("id"));
			command("say ת�����!");
			who->set_temp("shushan/changed","done");

return 1;
}
    
