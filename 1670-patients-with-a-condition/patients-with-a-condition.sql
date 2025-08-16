-- Find patients with a condition starting with 'DIAB1'
SELECT patient_id, patient_name, conditions
FROM patients
WHERE conditions LIKE 'DIAB1%'      -- condition starts with DIAB1
   OR conditions LIKE '% DIAB1%';   -- condition after a space starts with DIAB1
