string give_reward(object me) {
  mapping skill=me->query_skills();
  string *skillnames;
  string selected,msg;
  int level, inc=1,pot;

  if (!skill) return "none";

  skillnames=keys(skill);
        if (sizeof(skillnames) < 3) return "none";
  selected=skillnames[random(sizeof(skillnames))];

  // mon 3/25/99
  level=skill[selected];
if (level < 1) return "none";
  if(level<80) {
      inc=0;
  } else if(level<160) {
      inc=random(2);
  } else if(level<240) {
      inc=random(3);
  } else {
      inc=random(4);
  }

  if(!inc) {
    me->set_skill(selected,level+1);
//      pot=level*level*4;
//      me->improve_skill(selected,pot);
//    tell_object(me,"��õ���"+chinese_number(pot)+"��"+ to_chinese(selected) + "��\n");
    tell_object(me,"��õ���һ��"+ to_chinese(selected) + "��\n");
        me->add("mieyao/reward/skills",1);
    return selected;
  }
else
  return "none";
}
